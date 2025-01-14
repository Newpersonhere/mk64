#include <ultra64.h>
#include <macros.h>
#include "audio/heap.h"
#include "audio/load.h"
#include "audio/synthesis.h"
#include "audio/playback.h"
#include "audio/seqplayer.h"

/**
 * Given that (almost) all of these are format strings, it is highly likely
 * that they are meant to be used in some sort of printf variant. But I don't
 * care to try and figure out which function gets which string(s)
 * So I've place them all here instead.
**/
char heapAudioString00[] = "Warning:Kill Note  %x \n";
char heapAudioString01[] = "Kill Voice %d (ID %d) %d\n";
char heapAudioString02[] = "Warning: Running Sequence's data disappear!\n";
char heapAudioString03[] = "Audio:Memory:Heap OverFlow : Not Allocate %d!\n";
char heapAudioString04[] = "Audio:Memory:DataHeap Not Allocate \n";
char heapAudioString05[] = "StayHeap Not Allocate %d\n";
char heapAudioString06[] = "AutoHeap Not Allocate %d\n";
char heapAudioString07[] = "Status ID0 : %d  ID1 : %d\n";
char heapAudioString08[] = "id 0 is Stopping\n";
char heapAudioString09[] = "id 0 is Stop\n";
char heapAudioString10[] = "id 1 is Stopping\n";
char heapAudioString11[] = "id 1 is Stop\n";
char heapAudioString12[] = "WARNING: NO FREE AUTOSEQ AREA.\n";
char heapAudioString13[] = "WARNING: NO STOP AUTO AREA.\n";
char heapAudioString14[] = "         AND TRY FORCE TO STOP SIDE \n";
char heapAudioString15[] = "Check ID0  (seq ID %d) Useing ...\n";
char heapAudioString16[] = "Check ID1  (seq ID %d) Useing ...\n";
char heapAudioString17[] = "No Free Seq area.\n";
char heapAudioString18[] = "CH %d: ID %d\n";
char heapAudioString19[] = "TWO SIDES ARE LOADING... ALLOC CANCELED.\n";
char heapAudioString20[] = "WARNING: Before Area Overlaid After.";
char heapAudioString21[] = "WARNING: After Area Overlaid Before.";
char heapAudioString22[] = "MEMORY:SzHeapAlloc ERROR: sza->side %d\n";
char heapAudioString23[] = "Audio:MEMORY:SzHeap Overflow error. (%d bytes)\n";
char heapAudioString24[] = "Auto Heap Unhit for ID %d\n";
char heapAudioString25[] = "Heap Reconstruct Start %x\n";
char heapAudioString26[] = "AHPBASE %x\n";
char heapAudioString27[] = "AHPCUR  %x\n";
char heapAudioString28[] = "HeapTop %x\n";
char heapAudioString29[] = "SynoutRate %d / %d \n";
char heapAudioString30[] = "FXSIZE %d\n";
char heapAudioString31[] = "FXCOMP %d\n";
char heapAudioString32[] = "FXDOWN %d\n";
char heapAudioString33[] = "WaveCacheLen: %d\n";
char heapAudioString34[] = "SpecChange Finished\n";
char heapAudioString35[] = "Fbank Seq %x\n";
char heapAudioString36[] = "Already Load Type %d,ID %d\n";
char heapAudioString37[] = "Warning:Emem Over,not alloc %d\n";
char heapAudioString38[] = "Write %d\n";

extern u8 gUnkLoadStatus[];

void reset_bank_and_seq_load_status(void) {
    s32 i;
    for (i = 0; i < 64; i++) {
        if(gBankLoadStatus[i] != 5) {
            gBankLoadStatus[i] = 0;
        }
    }

    for (i = 0; i < 64; i++) {
        if(gUnkLoadStatus[i] != 5) {
            gUnkLoadStatus[i] = 0;
        }
    }

    for (i = 0; i < 256; i++) {
        if (gSeqLoadStatus[i] != 5) {
            gSeqLoadStatus[i] = 0;
        }
    }
}

void discard_bank(s32 bankId) {
    s32 i;

    for (i = 0; i < gMaxSimultaneousNotes; i++) {
        struct Note *note = &gNotes[i];

        if (note->noteSubEu.bankId == bankId) {
            // (These prints are unclear. Arguments are picked semi-randomly.)
            // eu_stubbed_printf_1("Warning:Kill Note  %x \n", i);
            if (note->priority >= NOTE_PRIORITY_MIN) {
                // eu_stubbed_printf_3("Kill Voice %d (ID %d) %d\n", note->waveId, bankId, note->priority);
                // eu_stubbed_printf_0("Warning: Running Sequence's data disappear!\n");
                note->parentLayer->enabled = FALSE; // is 0x48, should be 0x44
                note->parentLayer->finished = TRUE;
            }
            note_disable(note);
            audio_list_remove(&note->listItem);
            audio_list_push_back(&gNoteFreeLists.disabled, &note->listItem);
        }
    }
}

void discard_sequence(s32 seqId) {
    s32 i;

    for (i = 0; i < SEQUENCE_PLAYERS; i++) {
        if (gSequencePlayers[i].enabled && gSequencePlayers[i].seqId == seqId) {
            sequence_player_disable(&gSequencePlayers[i]);
        }
    }
}

void *soundAlloc(struct SoundAllocPool *pool, u32 size) {
    u8 *start;
    u8 *pos;
    u32 alignedSize = ALIGN16(size);

    start = pool->cur;
    if (start + alignedSize <= pool->start + pool->size) {
        pool->cur += alignedSize;
        for (pos = start; pos < pool->cur; pos++) {
            *pos = 0;
        }
    } else {
        // eu_stubbed_printf_1("Heap OverFlow : Not Allocate %d!\n", size);
        return NULL;
    }
    pool->numAllocatedEntries++;
    return start;
}

void sound_alloc_pool_init(struct SoundAllocPool *pool, void *memAddr, u32 size) {
    pool->cur = pool->start = (u8 *) ALIGN16((uintptr_t) memAddr);
    pool->size = size;
    pool->numAllocatedEntries = 0;
}

void persistent_pool_clear(struct PersistentPool *persistent) {
    persistent->pool.numAllocatedEntries = 0;
    persistent->pool.cur = persistent->pool.start;
    persistent->numEntries = 0;
}

void temporary_pool_clear(struct TemporaryPool *temporary) {
    temporary->pool.numAllocatedEntries = 0;
    temporary->pool.cur = temporary->pool.start;
    temporary->nextSide = 0;
    temporary->entries[0].ptr = temporary->pool.start;
    temporary->entries[1].ptr = temporary->pool.start + temporary->pool.size;
    temporary->entries[0].id = -1; // should be at 1e not 1c
    temporary->entries[1].id = -1;
}

void func_800B90E0(struct SoundAllocPool *pool) {
    pool->numAllocatedEntries = 0;
    pool->cur = pool->start;
}

// inspired by sound_init_main_pools in sm64
void func_800B90F0(s32 arg0) {
    sound_alloc_pool_init(&gAudioInitPool, &D_803B71B0, arg0);
    sound_alloc_pool_init(&gLeftVolRampings, D_803B71B0 + arg0, D_800EA5D0 - arg0);
}

// inspired by session_pools_init in sm64
void func_800B914C(struct PoolSplit *arg0) {
    gLeftVolRampings.cur = gLeftVolRampings.start;
    sound_alloc_pool_init(&gNotesAndBuffersPool, soundAlloc(&gLeftVolRampings, arg0->wantSeq), arg0->wantSeq);
    sound_alloc_pool_init(&gSeqAndBankPool, soundAlloc(&gLeftVolRampings, arg0->wantCustom), arg0->wantCustom);
}

void seq_and_bank_pool_init(struct PoolSplit2 *a) {
    gSeqAndBankPool.cur = gSeqAndBankPool.start;
    sound_alloc_pool_init(&gPersistentCommonPool, soundAlloc(&gSeqAndBankPool, a->wantPersistent), a->wantPersistent);
    sound_alloc_pool_init(&gTemporaryCommonPool, soundAlloc(&gSeqAndBankPool, a->wantTemporary), a->wantTemporary);
}

void persistent_pools_init(struct PoolSplit *a) {
    gPersistentCommonPool.cur = gPersistentCommonPool.start;
    sound_alloc_pool_init(&gSeqLoadedPool.persistent.pool, soundAlloc(&gPersistentCommonPool, a->wantSeq), a->wantSeq);
    sound_alloc_pool_init(&gBankLoadedPool.persistent.pool, soundAlloc(&gPersistentCommonPool, a->wantBank), a->wantBank);
    sound_alloc_pool_init(&gUnusedLoadedPool.persistent.pool, soundAlloc(&gPersistentCommonPool, a->wantUnused), a->wantUnused);
    persistent_pool_clear(&gSeqLoadedPool.persistent);
    persistent_pool_clear(&gBankLoadedPool.persistent);
    persistent_pool_clear(&gUnusedLoadedPool.persistent);
}

void temporary_pools_init(struct PoolSplit *a) {
    gTemporaryCommonPool.cur = gTemporaryCommonPool.start;
    sound_alloc_pool_init(&gSeqLoadedPool.temporary.pool, soundAlloc(&gTemporaryCommonPool, a->wantSeq), a->wantSeq);
    sound_alloc_pool_init(&gBankLoadedPool.temporary.pool, soundAlloc(&gTemporaryCommonPool, a->wantBank), a->wantBank);
    sound_alloc_pool_init(&gUnusedLoadedPool.temporary.pool, soundAlloc(&gTemporaryCommonPool, a->wantUnused), a->wantUnused);
    temporary_pool_clear(&gSeqLoadedPool.temporary);
    temporary_pool_clear(&gBankLoadedPool.temporary);
    temporary_pool_clear(&gUnusedLoadedPool.temporary);
}

#ifdef MIPS_TO_C
//generated by m2c commit eefca95b040d7ee0c617bc58f9ac6cd1cf7bce87 on Aug-15-2023
void *func_800B93BC(struct SoundMultiPool *arg0, s32 arg1, s32 size, s32 arg3, s32 id) {
    u8 *sp34;
    u8 sp33;
    struct TemporaryPool *sp28;
    struct SoundAllocPool *sp24;
    s32 sp20;
    s16 temp_a0;
    s16 temp_a2;
    s16 temp_v1_2;
    s32 var_a3;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    struct Note *var_v0;
    struct Note *var_v0_2;
    struct Note *var_v0_6;
    struct Note *var_v0_7;
    struct SequencePlayer *var_v0_4;
    struct SequencePlayer *var_v0_5;
    struct SoundAllocPool *temp_v1_3;
    struct SoundAllocPool *temp_v1_4;
    struct TemporaryPool *var_a3_2;
    u32 temp_a0_2;
    u32 temp_v1;
    u32 var_v0_3;
    u8 *temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;
    u8 *temp_v0_4;
    u8 *var_v0_8;
    u8 *var_v1;
    u8 var_t1;
    u8 var_t2;

    var_a3 = arg3;
loop_1:
    if (var_a3 == 0) {
        var_a3_2 = &arg0->temporary;
        if (arg0 == &gSeqLoadedPool) {
            sp34 = gSeqLoadStatus;
            sp33 = 0;
        } else if (arg0 == &gBankLoadedPool) {
            sp33 = 1;
            sp34 = gBankLoadStatus;
        } else if (arg0 == &gUnusedLoadedPool) {
            sp33 = 2;
            sp34 = gUnkLoadStatus;
        }
        temp_a2 = var_a3_2->entries[0].id;
        if (temp_a2 == -1) {
            var_t1 = 0;
        } else {
            var_t1 = sp34[temp_a2];
        }
        temp_a0 = var_a3_2->entries[1].id;
        if (temp_a0 == -1) {
            var_t2 = 0;
        } else {
            var_t2 = sp34[temp_a0];
        }
        sp20 = (s32) sp33;
        if (sp33 == 1) {
            if (var_t1 == 4) {
                var_v1_2 = 0;
                if (gMaxSimultaneousNotes > 0) {
                    var_v0 = gNotes;
loop_18:
                    if ((var_v0->noteSubEu.bankId != temp_a2) || (((u32) var_v0->unkB0 >> 0x1F) == 0)) {
                        var_v1_2 += 1;
                        var_v0 += 0xC0;
                        if (var_v1_2 < gMaxSimultaneousNotes) {
                            goto loop_18;
                        }
                    }
                }
                temp_v0 = &gBankLoadStatus[temp_a2];
                if (var_v1_2 == gMaxSimultaneousNotes) {
                    var_t1 = 3;
                    if (*temp_v0 != 5) {
                        *temp_v0 = 3;
                    }
                }
            }
            if (var_t2 == 4) {
                var_v1_3 = 0;
                if (gMaxSimultaneousNotes > 0) {
                    var_v0_2 = gNotes;
loop_27:
                    if ((var_v0_2->noteSubEu.bankId != var_a3_2->entries[1].id) || (((u32) var_v0_2->unkB0 >> 0x1F) == 0)) {
                        var_v1_3 += 1;
                        var_v0_2 += 0xC0;
                        if (var_v1_3 < gMaxSimultaneousNotes) {
                            goto loop_27;
                        }
                    }
                }
                if (var_v1_3 == gMaxSimultaneousNotes) {
                    temp_v0_2 = &gBankLoadStatus[var_a3_2->entries[1].id];
                    var_t2 = 3;
                    if (*temp_v0_2 != 5) {
                        *temp_v0_2 = 3;
                    }
                }
            }
        }
        if (var_t1 == 0) {
            var_a3_2->nextSide = 0;
            var_v0_3 = 0;
            goto block_84;
        }
        if (var_t2 == 0) {
            var_v0_3 = 1;
            var_a3_2->nextSide = 1;
            goto block_84;
        }
        if ((var_t1 == 3) && (var_t2 == 3)) {
            var_v0_3 = var_a3_2->nextSide;
            goto block_84;
        }
        if (var_t1 == 3) {
            var_a3_2->nextSide = 0;
            var_v0_3 = 0;
            goto block_84;
        }
        if (var_t2 == 3) {
            var_v0_3 = 1;
            var_a3_2->nextSide = 1;
            goto block_84;
        }
        if (sp20 == 0) {
            if (var_t1 == 2) {
                var_v0_4 = gSequencePlayers;
loop_47:
                if ((((u32) var_v0_4->unk0 >> 0x1F) == 0) || (var_v0_4->seqId != var_a3_2->entries[0].id)) {
                    var_v0_4 += 0x148;
                    if (var_v0_4 != gSequenceChannels) {
                        goto loop_47;
                    }
                }
                if (var_v0_4 == gSequenceChannels) {
                    var_a3_2->nextSide = 0;
                    var_v0_3 = 0;
                    goto block_84;
                }
                goto block_52;
            }
block_52:
            if (var_t2 == 2) {
                var_v0_5 = gSequencePlayers;
loop_54:
                if ((((u32) var_v0_5->unk0 >> 0x1F) == 0) || (var_v0_5->seqId != var_a3_2->entries[1].id)) {
                    var_v0_5 += 0x148;
                    if (var_v0_5 != gSequenceChannels) {
                        goto loop_54;
                    }
                }
                var_v0_3 = 1;
                if (var_v0_5 == gSequenceChannels) {
                    var_a3_2->nextSide = 1;
                    goto block_84;
                }
                goto block_76;
            }
            goto block_76;
        }
        if (sp20 == (s32) 1U) {
            if (var_t1 == 2) {
                var_v1_4 = 0;
                if (gMaxSimultaneousNotes > 0) {
                    var_v0_6 = gNotes;
loop_63:
                    if ((var_v0_6->noteSubEu.bankId != var_a3_2->entries[0].id) || (((u32) var_v0_6->unkB0 >> 0x1F) == 0)) {
                        var_v1_4 += 1;
                        var_v0_6 += 0xC0;
                        if (var_v1_4 < gMaxSimultaneousNotes) {
                            goto loop_63;
                        }
                    }
                }
                var_v0_3 = 0;
                if (var_v1_4 == gMaxSimultaneousNotes) {
                    var_a3_2->nextSide = 0;
                    goto block_84;
                }
                goto block_68;
            }
block_68:
            if (var_t2 == 2) {
                var_v1_5 = 0;
                if (gMaxSimultaneousNotes > 0) {
                    var_v0_7 = gNotes;
loop_71:
                    if ((var_v0_7->noteSubEu.bankId != var_a3_2->entries[1].id) || (((u32) var_v0_7->unkB0 >> 0x1F) == 0)) {
                        var_v1_5 += 1;
                        var_v0_7 += 0xC0;
                        if (var_v1_5 < gMaxSimultaneousNotes) {
                            goto loop_71;
                        }
                    }
                }
                var_v0_3 = 1;
                if (var_v1_5 == gMaxSimultaneousNotes) {
                    var_a3_2->nextSide = 1;
                    goto block_84;
                }
                goto block_76;
            }
            goto block_76;
        }
block_76:
        var_v0_3 = var_a3_2->nextSide;
        if (var_v0_3 == 0) {
            if (var_t1 == 1) {
                var_v0_3 = 1;
                if (var_t2 != 1) {
                    var_a3_2->nextSide = 1;
                    goto block_84;
                }
                goto block_83;
            }
            goto block_84;
        }
        if (var_t2 == 1) {
            var_v0_3 = 0;
            if (var_t1 != 1) {
                var_a3_2->nextSide = 0;
                goto block_84;
            }
block_83:
            return NULL;
        }
block_84:
        temp_v1_2 = var_a3_2->entries[var_v0_3].id;
        if (temp_v1_2 != -1) {
            sp34[temp_v1_2] = 0;
            if (sp20 == (s32) 1U) {
                sp28 = var_a3_2;
                discard_bank((s32) var_a3_2->entries[var_a3_2->nextSide].id);
            }
        }
        temp_a0_2 = var_a3_2->nextSide;
        temp_v1_3 = &arg0->temporary.pool;
        if (temp_a0_2 != 0) {
            temp_v1_4 = &arg0->temporary.pool;
            if (temp_a0_2 != 1) {
                return NULL;
            }
            var_a3_2->entries[1].id = (s16) id;
            var_v0_8 = (&temp_v1_4->start[temp_v1_4->size] - size) - 0x10;
            var_a3_2->entries[1].ptr = var_v0_8;
            var_a3_2->entries[1].size = (u32) size;
            if ((u32) var_v0_8 < (u32) temp_v1_4->cur) {
                sp34[var_a3_2->entries[0].id] = 0;
                switch (sp20) {                     /* switch 1; irregular */
                case 0:                             /* switch 1 */
                    sp28 = var_a3_2;
                    sp24 = temp_v1_4;
                    discard_sequence((s32) var_a3_2->entries[0].id);
block_106:
                    var_a3_2 = sp28;
                    break;
                case 1:                             /* switch 1 */
                    sp28 = var_a3_2;
                    sp24 = temp_v1_4;
                    discard_bank((s32) var_a3_2->entries[0].id);
                    goto block_106;
                }
                var_a3_2->entries[0].id = -1;
                temp_v1_4->cur = temp_v1_4->start;
                var_v0_8 = var_a3_2->entries[1].ptr;
            }
            var_v1 = var_v0_8;
            goto block_99;
        }
        var_a3_2->entries[0].id = (s16) id;
        var_a3_2->entries[0].ptr = temp_v1_3->start;
        var_a3_2->entries[0].size = (u32) size;
        temp_v0_3 = &temp_v1_3->start[size];
        temp_v1_3->cur = temp_v0_3;
        if ((u32) var_a3_2->entries[1].ptr < (u32) temp_v0_3) {
            sp34[var_a3_2->entries[1].id] = 0;
            switch (sp20) {                         /* irregular */
            case 0:
                sp28 = var_a3_2;
                sp24 = temp_v1_3;
                discard_sequence((s32) var_a3_2->entries[1].id);
block_96:
                var_a3_2 = sp28;
                break;
            case 1:
                sp28 = var_a3_2;
                sp24 = temp_v1_3;
                discard_bank((s32) var_a3_2->entries[1].id);
                goto block_96;
            }
            var_a3_2->entries[1].id = -1;
            var_a3_2->entries[1].ptr = &temp_v1_3->start[temp_v1_3->size];
        }
        var_v1 = var_a3_2->entries[0].ptr;
block_99:
        var_a3_2->nextSide ^= 1;
        return var_v1;
    }
    arg3 = var_a3;
    temp_v0_4 = soundAlloc(&arg0->persistent.pool, arg1 * size);
    arg0->persistent.entries[arg0->persistent.numEntries].ptr = temp_v0_4;
    if (temp_v0_4 == NULL) {
        if ((arg3 != 0) && (arg3 != 1)) {
            if (arg3 == 2) {
                var_a3 = 0;
                goto loop_1;
            }
            goto block_116;
        }
        return NULL;
    }
block_116:
    arg0->persistent.entries[arg0->persistent.numEntries].id = (s16) id;
    arg0->persistent.entries[arg0->persistent.numEntries].size = (u32) size;
    temp_v1 = arg0->persistent.numEntries;
    arg0->persistent.numEntries = temp_v1 + 1;
    return arg0->persistent.entries[temp_v1].ptr;
}
#else
GLOBAL_ASM("asm/non_matchings/audio/heap/func_800B93BC.s")
#endif

void *get_bank_or_seq(s32 poolIdx, s32 arg1, s32 id) {
    void *ret;

    ret = unk_pool1_lookup(poolIdx, id);
    if (ret != NULL) {
        return ret;
    }
    return get_bank_or_seq_inner(poolIdx, arg1, id);
}

void *get_bank_or_seq_inner(s32 poolIdx, s32 arg1, s32 bankId) {
    u32 i;
    struct SoundMultiPool* loadedPool;
    struct TemporaryPool* temporary;
    struct PersistentPool* persistent;

    switch (poolIdx) {
        case 0:
            loadedPool = &gSeqLoadedPool;
            break;
        case 1:
            loadedPool = &gBankLoadedPool;
            break;
        case 2:
            loadedPool = &gUnusedLoadedPool;
            break;
    }

    temporary = &loadedPool->temporary;
    if (arg1 == 0) {
        if (temporary->entries[0].id == bankId) {
            temporary->nextSide = 1;
            return temporary->entries[0].ptr;
        } else if (temporary->entries[1].id == bankId) {
            temporary->nextSide = 0;
            return temporary->entries[1].ptr;
        } else {
            return NULL;
        }
    }

    persistent = &loadedPool->persistent;
    for (i = 0; i < persistent->numEntries; i++) {
        if (persistent->entries[i].id == bankId) {
            return persistent->entries[i].ptr;
        }
    }

    if (arg1 == 2) {
        return get_bank_or_seq(poolIdx, 0, bankId);
    }
    return NULL;
}

#ifdef NEEDS_RODATA
// inspired by func_eu_802e27e4_unused from SM64
void func_800B9BE4(f32 arg0, f32 arg1, u16 *arg2) {
    s32 i;
    f32 tmp[16];

    tmp[0] = arg1 * 262159.0f;
    tmp[8] = arg0 * 262159.0f;
    tmp[1] = (arg1 * arg0) * 262159.0f;
    tmp[9] = ((arg0 * arg0) + arg1) * 262159.0f;

    for (i = 2; i < 8; i++) {
        //! @bug they probably meant to store the value to tmp[i] and tmp[8 + i]
        arg2[i] = arg1 * tmp[i - 2] + arg0 * tmp[i - 1];
        arg2[8 + i] = arg1 * tmp[6 + i] + arg0 * tmp[7 + i];
    }

    for (i = 0; i < 16; i++) {
        arg2[i] = tmp[i];
    }
}
#else
GLOBAL_ASM("asm/non_matchings/audio/heap/func_800B9BE4.s")
#endif

// inspired by decrease_reverb_gain from SM64
void func_800B9FB8(void) {
    s32 i;
    for (i = 0; i < gNumSynthesisReverbs; i++) {
        gSynthesisReverbs[i].reverbGain -= gSynthesisReverbs[i].reverbGain / 4;
    }
}

#ifdef MIPS_TO_C
//generated by m2c commit eefca95b040d7ee0c617bc58f9ac6cd1cf7bce87 on Aug-14-2023
? func_800B9FB8();                                  /* extern */
? func_800BA250();                                  /* extern */
extern u8 D_803B0500;
extern s32 D_803B0504;
extern s32 D_803B7180;
extern ? D_803B718C;

s32 func_800BA00C(void) {
    s32 *var_v1_2;
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;
    struct SequencePlayer *var_s0;
    void *temp_t1;
    void *temp_v0;
    void *temp_v0_2;

    switch (D_803B0500) {
    case 5:
        var_s0 = gSequencePlayers;
        do {
            sequence_player_disable(var_s0);
            var_s0 += 0x148;
        } while (var_s0 != gSequenceChannels);
        D_803B0504 = 4;
        D_803B0500 -= 1;
        break;
    case 4:
        if (D_803B0504 != 0) {
            D_803B0504 -= 1;
            func_800B9FB8();
        } else {
            var_a0 = 0;
            var_v1 = 0;
            if (gMaxSimultaneousNotes > 0) {
                do {
                    var_a0 += 1;
                    temp_v0 = gNotes + var_v1;
                    if ((((u32) temp_v0->unkB0 >> 0x1F) != 0) && (temp_v0->unk59 != 0)) {
                        temp_v0->unk68 = (f32) gAudioBufferParameters.updatesPerFrameInv;
                        temp_v0_2 = gNotes + var_v1;
                        temp_v0_2->unk58 = (u8) (temp_v0_2->unk58 | 0x10);
                    }
                    var_v1 += 0xC0;
                } while (var_a0 < gMaxSimultaneousNotes);
            }
            D_803B0504 = 0x00000010;
            D_803B0500 -= 1;
        }
        break;
    case 3:
        var_v1_2 = &D_803B7180;
        if (D_803B0504 != 0) {
            D_803B0504 -= 1;
            func_800B9FB8();
        } else {
            do {
                var_v0 = 0;
loop_18:
                *(*var_v1_2 + var_v0) = 0;
                (*var_v1_2 + var_v0)->unk2 = 0;
                (*var_v1_2 + var_v0)->unk4 = 0;
                temp_t1 = *var_v1_2 + var_v0;
                var_v0 += 8;
                temp_t1->unk6 = 0;
                if (var_v0 != 0xA00) {
                    goto loop_18;
                }
                var_v1_2 += 4;
            } while (var_v1_2 != &D_803B718C);
            D_803B0504 = 4;
            D_803B0500 -= 1;
        }
        break;
    case 2:
        if (D_803B0504 != 0) {
            D_803B0504 -= 1;
        } else {
            D_803B0500 -= 1;
        }
        break;
    case 1:
        func_800BA250();
        D_803B0500 = 0;
        break;
    }
    if ((s32) D_803B0500 < 3) {
        return 0;
    }
    return 1;
}
#else
GLOBAL_ASM("asm/non_matchings/audio/heap/func_800BA00C.s")
#endif

#ifdef MIPS_TO_C
//generated by m2c commit eefca95b040d7ee0c617bc58f9ac6cd1cf7bce87 on Aug-15-2023
? func_800B914C(? *, s16, s16, u16);                /* extern */
? reset_bank_and_seq_load_status();                 /* extern */
extern s32 D_803AFBD0;
extern ? D_803B0348;
extern struct PoolSplit2 D_803B0358;
extern struct PoolSplit D_803B0360;
extern struct PoolSplit D_803B0370;
extern u8 D_803B0501;
extern s32 D_803B70AC;
extern s16 D_803B70B4;
extern ? D_803B70C8;
extern ? D_803B70D0;
extern f32 D_803B7178;
extern s32 D_803B717C;
extern s32 gSampleDmaNumListItems;
extern u16 gVolume;
extern ? sAudioSynthesisPad;
static ? D_800EA4D8;                                /* unable to generate initializer */
static s16 D_800EA5CC;                              /* unable to generate initializer */

void func_800BA250(void) {
    ? *var_s0;
    f32 temp_f0;
    s16 *temp_v0_2;
    s16 *temp_v0_3;
    s16 temp_a2;
    s16 temp_t0;
    s32 temp_t2;
    s32 temp_t9;
    s32 var_s1;
    s32 var_s5;
    struct SynthesisReverb *var_s0_2;
    struct SynthesisReverb *var_s2;
    struct SynthesisReverb *var_s2_2;
    u16 temp_t7;
    u32 temp_s0;
    u32 temp_s1;
    u8 temp_v1;
    void *temp_s6;
    void *temp_v0;

    temp_s6 = (D_803B0501 * 0x28) + &D_800EA4D8;
    gSampleDmaNumListItems = 0;
    temp_t9 = temp_s6->unk0;
    gAudioBufferParameters.frequency = (u16) temp_t9;
    gAudioBufferParameters.aiFrequency = osAiSetFrequency(temp_t9 & 0xFFFF);
    gAudioBufferParameters.samplesPerFrameTarget = (((s32) gAudioBufferParameters.frequency / (s32) D_803B717C) + 0xF) & 0xFFF0;
    temp_t0 = gAudioBufferParameters.samplesPerFrameTarget + 0x10;
    gAudioBufferParameters.minAiBufferLength = gAudioBufferParameters.samplesPerFrameTarget - 0x10;
    gAudioBufferParameters.maxAiBufferLength = temp_t0;
    gAudioBufferParameters.updatesPerFrame = (temp_t0 / 192) + 1;
    temp_a2 = gAudioBufferParameters.updatesPerFrame;
    gAudioBufferParameters.samplesPerUpdate = ((s16) gAudioBufferParameters.samplesPerFrameTarget / temp_a2) & 0xFFF8;
    temp_f0 = (f32) temp_a2;
    gAudioBufferParameters.samplesPerUpdateMax = gAudioBufferParameters.samplesPerUpdate + 8;
    gAudioBufferParameters.samplesPerUpdateMin = gAudioBufferParameters.samplesPerUpdate - 8;
    gAudioBufferParameters.resampleRate = 32000.0f / (f32) gAudioBufferParameters.frequency;
    gAudioBufferParameters.unkUpdatesPerFrameScaled = 0.001171875f / temp_f0;
    gAudioBufferParameters.updatesPerFrameInv = 1.0f / temp_f0;
    gMaxSimultaneousNotes = (s32) temp_s6->unk5;
    gVolume = temp_s6->unkC;
    D_803B70B4 = (s16) (u32) (((temp_f0 * 2880000.0f) / (f32) D_800EA5CC) / D_803B7178);
    gAudioBufferParameters.presetUnk4 = (s16) temp_s6->unk4;
    gAudioBufferParameters.samplesPerFrameTarget *= gAudioBufferParameters.presetUnk4;
    gAudioBufferParameters.maxAiBufferLength *= gAudioBufferParameters.presetUnk4;
    gAudioBufferParameters.minAiBufferLength *= gAudioBufferParameters.presetUnk4;
    gAudioBufferParameters.updatesPerFrame = temp_a2 * gAudioBufferParameters.presetUnk4;
    D_803B70AC = (gMaxSimultaneousNotes * 0x14 * gAudioBufferParameters.updatesPerFrame) + (temp_s6->unk6 << 5) + 0x1E0;
    temp_s0 = temp_s6->unk10 + temp_s6->unk14 + temp_s6->unk18;
    temp_s1 = temp_s6->unk1C + temp_s6->unk20 + temp_s6->unk24;
    temp_t2 = temp_s0 + temp_s1;
    D_803B0348.unk0 = (s32) ((D_803AFBD0 - temp_t2) - 0x100);
    D_803B0348.unkC = temp_t2;
    func_800B914C(&D_803B0348, gAudioBufferParameters.presetUnk4, temp_a2, gAudioBufferParameters.frequency);
    D_803B0358.wantPersistent = temp_s0;
    D_803B0358.wantTemporary = temp_s1;
    seq_and_bank_pool_init(&D_803B0358);
    D_803B0360.wantSeq = temp_s6->unk10;
    D_803B0360.wantBank = temp_s6->unk14;
    D_803B0360.wantUnused = temp_s6->unk18;
    persistent_pools_init(&D_803B0360);
    D_803B0370.wantSeq = temp_s6->unk1C;
    D_803B0370.wantBank = temp_s6->unk20;
    D_803B0370.wantUnused = temp_s6->unk24;
    temporary_pools_init(&D_803B0370);
    reset_bank_and_seq_load_status();
    gNotes = soundAlloc(&gNotesAndBuffersPool, gMaxSimultaneousNotes * 0xC0);
    note_init_all();
    init_note_free_list();
    gNoteSubsEu = soundAlloc(&gNotesAndBuffersPool, gAudioBufferParameters.updatesPerFrame * gMaxSimultaneousNotes * 0x10);
    var_s0 = &D_803B70C8;
    do {
        var_s0 += 4;
        var_s0->unk-4 = soundAlloc(&gNotesAndBuffersPool, D_803B70AC * 8);
    } while (var_s0 != &D_803B70D0);
    var_s2 = gSynthesisReverbs;
    do {
        var_s2 += 0x108;
        var_s2->unk-107 = 0;
    } while ((u32) var_s2 < (u32) &sAudioSynthesisPad);
    gNumSynthesisReverbs = (s8) temp_s6->unk6;
    var_s2_2 = gSynthesisReverbs;
    var_s5 = 0;
    if (gNumSynthesisReverbs > 0) {
        do {
            temp_v0 = temp_s6->unk8 + (var_s5 * 4);
            temp_t7 = temp_v0->unk1 << 6;
            var_s2_2->windowSize = temp_t7;
            var_s2_2->downsampleRate = temp_v0->unk0;
            var_s2_2->useReverb = 8;
            var_s2_2->reverbGain = temp_v0->unk2;
            var_s2_2->ringBuffer.left = soundAlloc(&gNotesAndBuffersPool, (temp_t7 & 0xFFFF) * 2);
            temp_v1 = var_s2_2->downsampleRate;
            var_s2_2->ringBuffer.right = soundAlloc(&gNotesAndBuffersPool, var_s2_2->windowSize * 2);
            var_s2_2->nextRingBufferPos = 0;
            var_s2_2->unkC = 0;
            var_s2_2->curFrame = 0;
            var_s2_2->framesLeftToIgnore = 2;
            var_s2_2->bufSizePerChannel = (s32) var_s2_2->windowSize;
            if (temp_v1 != 1) {
                var_s2_2->resampleFlags = 1;
                var_s2_2->resampleRate = (u16) (0x8000 / (s32) temp_v1);
                var_s1 = 0;
                var_s2_2->resampleStateLeft = soundAlloc(&gNotesAndBuffersPool, 0x00000020U);
                var_s2_2->resampleStateRight = soundAlloc(&gNotesAndBuffersPool, 0x00000020U);
                var_s2_2->unk24 = soundAlloc(&gNotesAndBuffersPool, 0x00000020U);
                var_s2_2->unk28 = soundAlloc(&gNotesAndBuffersPool, 0x00000020U);
                if (gAudioBufferParameters.updatesPerFrame > 0) {
                    var_s0_2 = var_s2_2;
                    do {
                        temp_v0_2 = soundAlloc(&gNotesAndBuffersPool, 0x00000300U);
                        var_s0_2->items[0][0].toDownsampleLeft = temp_v0_2;
                        var_s0_2->items[0][0].toDownsampleRight = temp_v0_2 + 0x180;
                        temp_v0_3 = soundAlloc(&gNotesAndBuffersPool, 0x00000300U);
                        var_s0_2->items[1][0].toDownsampleLeft = temp_v0_3;
                        var_s0_2->items[1][0].toDownsampleRight = temp_v0_3 + 0x180;
                        var_s1 += 1;
                        var_s0_2 += 0x14;
                    } while (var_s1 < gAudioBufferParameters.updatesPerFrame);
                }
            }
            var_s5 += 1;
            var_s2_2 += 0x108;
        } while (var_s5 < gNumSynthesisReverbs);
    }
    func_800BB030(gMaxSimultaneousNotes);
    osWritebackDCacheAll();
}
#else
GLOBAL_ASM("asm/non_matchings/audio/heap/func_800BA250.s")
#endif

void *unk_pool1_lookup(s32 poolIdx, s32 id) {
    s32 i;

    for (i = 0; i < gUnkPool1.pool.numAllocatedEntries; i++) {
        if (gUnkPool1.entries[i].poolIndex == poolIdx && gUnkPool1.entries[i].id == id) {
            return gUnkPool1.entries[i].ptr;
        }
    }
    return NULL;
}

#ifdef MIPS_TO_C
//generated by m2c commit eefca95b040d7ee0c617bc58f9ac6cd1cf7bce87 on Aug-14-2023
? func_800BB584(s32);                               /* extern */
extern s32 D_803B706C;
extern s32 D_803B7070;
extern s32 D_803B7074;

void func_800BA8B0(s32 arg0, s32 arg1) {
    s32 sp3C;
    s32 sp38;
    u32 sp34;
    u32 sp30;
    void *sp20;
    s32 temp_a2;
    s32 var_s1;
    u32 temp_a1;
    u32 var_a3;
    u8 *temp_v0_3;
    u8 *temp_v0_4;
    u8 *temp_v0_5;
    void *temp_v0;
    void *temp_v0_2;

    var_s1 = arg1;
    switch (arg0) {                                 /* irregular */
    case 0:
        sp3C = D_803B706C;
        break;
    case 1:
        sp3C = D_803B7070;
        break;
    case 2:
        sp3C = D_803B7074;
        break;
    }
    temp_v0 = sp3C + (var_s1 * 8);
    if (temp_v0->unk8 == 0) {
        var_s1 = temp_v0->unk4;
    }
    if (unk_pool1_lookup(arg0, var_s1) == NULL) {
        temp_v0_2 = sp3C + (var_s1 * 8);
        temp_a2 = gUnkPool1.pool.numAllocatedEntries;
        temp_a1 = temp_v0_2->unk8;
        var_a3 = temp_v0_2->unk4;
        if (arg0 == 1) {
            var_a3 += 0x10;
        }
        sp34 = temp_a1;
        sp38 = temp_a2;
        sp30 = var_a3;
        temp_v0_3 = soundAlloc(&gUnkPool1.pool, temp_a1);
        gUnkPool1.entries[temp_a2].ptr = temp_v0_3;
        if (temp_v0_3 != NULL) {
            sp20 = (temp_a2 * 0xC) + &gUnkPool1;
            audio_dma_copy_immediate(var_a3, temp_v0_3, sp34);
            gUnkPool1.entries[temp_a2].poolIndex = (s16) arg0;
            gUnkPool1.entries[temp_a2].id = (s16) var_s1;
            gUnkPool1.entries[temp_a2].size = sp34;
            switch (arg0) {                         /* switch 1; irregular */
            case 0:                                 /* switch 1 */
                temp_v0_4 = &gSeqLoadStatus[var_s1];
                if (*temp_v0_4 != 5) {
                    *temp_v0_4 = 5;
                    return;
                }
                break;
            case 1:                                 /* switch 1 */
                gCtlEntries[var_s1].instruments = (struct Instrument **) (gUnkPool1.entries[temp_a2].ptr + 4);
                func_800BB584(var_s1);
                temp_v0_5 = &gBankLoadStatus[var_s1];
                if (*temp_v0_5 != 5) {
                    *temp_v0_5 = 5;
                }
                break;
            }
        }
    } else {
    case 2:                                         /* switch 1 */
    }
}
#else
GLOBAL_ASM("asm/non_matchings/audio/heap/func_800BA8B0.s")
#endif
