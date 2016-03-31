/*
  ==============================================================================

    CopyableTone.cpp
    Created: 31 Mar 2016 9:20:30am
    Author:  Spindler

  ==============================================================================
*/

#include "CopyableTone.h"

#include "OverallMemoryBlock.h"

extern OverallMemoryBlock* grooveboxMemory;

/*
■1-3-2.Patch Tone
+——————————————————————————————————————————————————————————————————————————————+
| Offset      |           |                                                    | Correspondence between the "Waveform List" and "Wave Group Type, Wave Group ID, Wave Number":
|     Address | Size      | Description                     Data    (Value)    |    +———————————————————————————————————————————————————————————+
|—————————————+————————————————————————————————————————————————————————————————|    |Wave      | Wave Group Type  | Wave Group ID  | Wave Number|
|       00 00 | 0000 000a | Tone Switch                     0 - 1   (OFF,ON)   | 	+———————————————————————————————————————————————————————————+
|       00 01 | 0000 0000 | Wave Group Type                 0                  | 	|A001-254  |        0         |        1       |     0 - 253|
|       00 02 | 0000 00aa | Wave Group ID                   0 - 3              | 	|B001-251  |        0         |        2       |     0 - 250|
|#      00 03 | 0000 aaaa | Wave Number                     0 - 253            | 	|C001-236  |        0         |        3       |     0 - 235|
|             | 0000 bbbb |                                         (001 - 254)| 	+———————————————————————————————————————————————————————————+
|       00 05 | 0000 00aa | Wave Gain                       0 - 3              |  -6, 0, +6, +12
|       00 06 | 0000 000a | FXM Switch                      0 - 1   (OFF,ON)   |
|       00 07 | 0000 00aa | FXM Color                       0 - 3   (1 - 4)    |
|       00 08 | 0000 aaaa | FXM Depth                       0 - 15  (1 - 16)   |
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 09 | 0aaa aaaa | JV-2080 Delay Mode              0 - 7              | NORMAL, HOLD, PLAYMATE, CLOCK-SYNC, TAP-SYNC, KEY-OFF-NORMAL, KEY-OFF-DECAY, TEMPO-SYNC
|       00 0A | 0aaa aaaa | JV-2080 Delay Time              0 - 127            |
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 0B | 0aaa aaaa | Velocity Cross Fade             0 - 127            |
|       00 0C | 0aaa aaaa | Velocity Range Lower            1 - 127            | 1     - Upper
|       00 0D | 0aaa aaaa | Velocity Range Upper            1 - 127            | Lower -   127
|       00 0E | 0aaa aaaa | Keyboard Range Lower            0 - 127            | C -1  - Upper
|       00 0F | 0aaa aaaa | Keyboard Range Upper            0 - 127            | Lower -   G 9
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 10 | 0000 000a | JV-2080 Redamper Control Switch 0 - 1   (OFF,ON)   |
|       00 11 | 0000 000a | JV-2080 Volume Control Switch   0 - 1   (OFF,ON)   |
|       00 12 | 0000 000a | JV-2080 Hold-1 Control Switch   0 - 1   (OFF,ON)   |
|       00 13 | 0000 000a | JV-2080 Pitch Bend Control Swit 0 - 1   (OFF,ON)   |
|       00 14 | 0000 000a | JV-2080 Pan Control Switch      0 - 1   (OFF,ON)   |
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 15 | 000a aaaa | Modulation Destination 1        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 16 | 0aaa aaaa | Modulation Depth 1              0 - 126 (-63 - +63)|
|       00 17 | 000a aaaa | Modulation Destination 2        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 18 | 0aaa aaaa | Modulation Depth 2              0 - 126 (-63 - +63)|
|       00 19 | 000a aaaa | Modulation Destination 3        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 1A | 0aaa aaaa | Modulation Depth 3              0 - 126 (-63 - +63)|
|       00 1B | 000a aaaa | Modulation Destination 4        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 1C | 0aaa aaaa | Modulation Depth 4              0 - 126 (-63 - +63)|
|       00 1D | 000a aaaa | Pitch Bend Destination 1        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 1E | 0aaa aaaa | Pitch Bend Depth 1              0 - 126 (-63 - +63)|
|       00 1F | 000a aaaa | Pitch Bend Destination 2        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 20 | 0aaa aaaa | Pitch Bend Depth 2              0 - 126 (-63 - +63)|
|       00 21 | 000a aaaa | Pitch Bend Destination 3        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 22 | 0aaa aaaa | Pitch Bend Depth 3              0 - 126 (-63 - +63)|
|       00 23 | 000a aaaa | Pitch Bend Destination 4        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 24 | 0aaa aaaa | Pitch Bend Depth 4              0 - 126 (-63 - +63)|
|       00 25 | 000a aaaa | Aftertouch Destination 1        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 26 | 0aaa aaaa | Aftertouch Depth 1              0 - 126 (-63 - +63)|
|       00 27 | 000a aaaa | Aftertouch Destination 2        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 28 | 0aaa aaaa | Aftertouch Depth 2              0 - 126 (-63 - +63)|
|       00 29 | 000a aaaa | Aftertouch Destination 3        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 2A | 0aaa aaaa | Aftertouch Depth 3              0 - 126 (-63 - +63)|
|       00 2B | 000a aaaa | Aftertouch Destination 4        0 - 15             | OFF, PCH, CUT, RES, LEV, PAN, L1P, LP2, L1F, L2F, L1A, L2A, PL1, PL2, L1R, L2R
|       00 2C | 0aaa aaaa | Aftertouch Depth 4              0 - 126 (-63 - +63)|
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 2D | 0000 0aaa | LFO1 Waveform                   0 - 7              | TRI, SIN, SAW, SQR, TRP, S&H, RND, CHS
|       00 2E | 0000 000a | LFO1 Key Sync                   0 - 1   (OFF,ON)   |
|       00 2F | 0aaa aaaa | LFO1 Rate                       0 - 127            |
|       00 30 | 0000 0aaa | LFO1 Offset                     0 - 4              | -100, -50, 0, +50, +100
|       00 31 | 0aaa aaaa | LFO1 Delay Time                 0 - 127            |
|       00 32 | 0000 00aa | LFO1 Fade Mode                  0 - 3              | ON-IN, ON-OUT, OFF-IN, OFF-OUT
|       00 33 | 0aaa aaaa | LFO1 Fade Time                  0 - 127            |
|       00 34 | 0000 000a | LFO1 Tempo Sync                 0 - 1   (OFF,ON)   |
|       00 35 | 0000 0aaa | LFO2 Waveform                   0 - 7              | TRI, SIN, SAW, SQR, TRP, S&H, RND, CHS
|       00 36 | 0000 000a | LFO2 Key Sync                   0 - 1   (OFF,ON)   |
|       00 37 | 0aaa aaaa | LFO2 Rate                       0 - 127            |
|       00 38 | 0000 0aaa | LFO2 Offset                     0 - 4              | -100, -50, 0, +50, +100
|       00 39 | 0aaa aaaa | LFO2 Delay Time                 0 - 127            |
|       00 3A | 0000 00aa | LFO2 Fade Mode                  0 - 3              | ON-IN, ON-OUT, OFF-IN, OFF-OUT
|       00 3B | 0aaa aaaa | LFO2 Fade Time                  0 - 127            |
|       00 3C | 0000 000a | LFO2 Tempo Sync                 0 - 1   (OFF,ON)   |
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 3D | 0aaa aaaa | Coarse Tune                     0 - 96  (-48 - +48)|
|       00 3E | 0aaa aaaa | Fine Tune                       0 - 100 (-50 - +50)|
|       00 3F | 000a aaaa | Random Pitch Depth              0 - 30             | 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200
|       00 40 | 0000 aaaa | Pitch Keyfollow                 0 - 15             | -100, -70, -50, -30, -10, 0, +10, +20, +30, +40, +50, +70, +100, +120, +150, +200
|       00 41 | 000a aaaa | Pitch Envelope Depth            0 - 24  (-12 - +12)|
|       00 42 | 0aaa aaaa | Pitch Envelope Velocity Sens    0 - 125            | -100 - +150
|       00 43 | 0000 aaaa | Pitch Envelope Velocity Time1   0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 44 | 0000 aaaa | Pitch Envelope Velocity Time4   0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 45 | 0000 aaaa | Pitch Envelope Time Keyfollow   0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 46 | 0aaa aaaa | Pitch Envelope Time 1           0 - 127            |
|       00 47 | 0aaa aaaa | Pitch Envelope Time 2           0 - 127            |
|       00 48 | 0aaa aaaa | Pitch Envelope Time 3           0 - 127            |
|       00 49 | 0aaa aaaa | Pitch Envelope Time 4           0 - 127            |
|       00 4A | 0aaa aaaa | Pitch Envelope Level 1          0 - 126 (-63 - +63)|
|       00 4B | 0aaa aaaa | Pitch Envelope Level 2          0 - 126 (-63 - +63)|
|       00 4C | 0aaa aaaa | Pitch Envelope Level 3          0 - 126 (-63 - +63)|
|       00 4D | 0aaa aaaa | Pitch Envelope Level 4          0 - 126 (-63 - +63)|
|       00 4E | 0aaa aaaa | Pitch LFO1 Depth                0 - 126 (-63 - +63)|
|       00 4F | 0aaa aaaa | Pitch LFO2 Depth                0 - 126 (-63 - +63)|
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 50 | 0000 0aaa | Filter Type                     0 - 4              |  OFF, LPF, BPF, HPF, PKG
|       00 51 | 0aaa aaaa | Cutoff Frequency                0 - 127            |
|       00 52 | 0000 aaaa | Cutoff Keyfollow                0 - 15             | -100, -70, -50, -30, -10, 0, +10, +20, +30, +40, +50, +70, +100, +120, +150, +200
|       00 53 | 0aaa aaaa | Resonance                       0 - 127            |
|       00 54 | 0aaa aaaa | Resonance Velocity Sens         0 - 125            | -100 - +150
|       00 55 | 0aaa aaaa | Filter Envelope Depth           0 - 126 (-63 - +63)|
|       00 56 | 0000 0aaa | Filter Envelope Velocity Curve  0 - 6   (1 - 7)    |
|       00 57 | 0aaa aaaa | Filter Envelope Velocity Sens   0 - 125            | -100 - +150
|       00 58 | 0000 aaaa | Filter Envelope Velocity Time1  0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 59 | 0000 aaaa | Filter Envelope Velocity Time4  0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 5A | 0000 aaaa | Filter Envelope Time Keyfollow  0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 5B | 0aaa aaaa | Filter Envelope Time 1          0 - 127            |
|       00 5C | 0aaa aaaa | Filter Envelope Time 2          0 - 127            |
|       00 5D | 0aaa aaaa | Filter Envelope Time 3          0 - 127            |
|       00 5E | 0aaa aaaa | Filter Envelope Time 4          0 - 127            |
|       00 5F | 0aaa aaaa | Filter Envelope Level 1         0 - 127            |
|       00 60 | 0aaa aaaa | Filter Envelope Level 2         0 - 127            |
|       00 61 | 0aaa aaaa | Filter Envelope Level 3         0 - 127            |
|       00 62 | 0aaa aaaa | Filter Envelope Level 4         0 - 127            |
|       00 63 | 0aaa aaaa | Filter LFO1 Depth               0 - 126 (-63 - +63)|
|       00 64 | 0aaa aaaa | Filter LFO2 Depth               0 - 126 (-63 - +63)|
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 65 | 0aaa aaaa | Tone Level                      0 - 127            |
|       00 66 | 0000 00aa | Bias Direction                  0 - 3              | LOWER, UPPER, LOW&UP, ALL
|       00 67 | 0aaa aaaa | Bias Point                      0 - 127 (C-1 - G9) |
|       00 68 | 0000 aaaa | Bias Level                      0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 69 | 0000 0aaa | Amp Envelope Velocity Curve     0 - 6  (1 - 7)     |
|       00 6A | 0aaa aaaa | Amp Envelope Velocity Sens      0 - 125            | -100 - +150
|       00 6B | 0000 aaaa | Amp Envelope Velocity Time1     0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 6C | 0000 aaaa | Amp Envelope Velocity Time4     0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 6D | 0000 aaaa | Amp Envelope Time Keyfollow     0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 6E | 0aaa aaaa | Amp Envelope Time 1             0 - 127            |
|       00 6F | 0aaa aaaa | Amp Envelope Time 2             0 - 127            |
|       00 70 | 0aaa aaaa | Amp Envelope Time 3             0 - 127            |
|       00 71 | 0aaa aaaa | Amp Envelope Time 4             0 - 127            |
|       00 72 | 0aaa aaaa | Amp Envelope Level 1            0 - 127            |
|       00 73 | 0aaa aaaa | Amp Envelope Level 2            0 - 127            |
|       00 74 | 0aaa aaaa | Amp Envelope Level 3            0 - 127            |
|       00 75 | 0aaa aaaa | Amp LFO1 Depth                  0 - 126 (-63 - +63)|
|       00 76 | 0aaa aaaa | Amp LFO2 Depth                  0 - 126 (-63 - +63)|
|       00 77 | 0aaa aaaa | Tone Pan                        0 - 127 (L64 - 63R)|
|       00 78 | 0000 aaaa | Pan Key follow                  0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 79 | 00aa aaaa | Random Pan Switch               0,63    (OFF,ON)   |
|       00 7A | 0aaa aaaa | Alternate Pan Depth             1 - 127 (L63 - 63R)|
|       00 7B | 0aaa aaaa | Pan LFO1 Depth                  0 - 126 (-63 - +63)|
|       00 7C | 0aaa aaaa | Pan LFO2 Depth                  0 - 126 (-63 - +63)|
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 7D | 0000 00aa | JV-2080 Output Assign           0 - 3              | MIX, EFX, DIR1, DIR2
|       00 7E | 0aaa aaaa | JV-2080 Mix/EFX Send Level      0 - 127            |
|       00 7F | 0aaa aaaa | JV-2080 Chorus Send Level       0 - 127            |
|       01 00 | 0aaa aaaa | JV-2080 Reverb Send Level       0 - 127            |
|—————————————+————————————————————————————————————————————————————————————————|
| Total size  | 00 00 01 01                                                    |
+——————————————————————————————————————————————————————————————————————————————+

■1-4-2.Rhythm Note
+——————————————————————————————————————————————————————————————————————————————+
| Offset      |           |                                                    | Correspondence between the "Waveform List" and "Wave Group Type, Wave Group ID, Wave Number":
|     Address | Size      | Description                     Data    (Value)    |    +———————————————————————————————————————————————————————————+
|—————————————+————————————————————————————————————————————————————————————————|    |Wave      | Wave Group Type  | Wave Group ID  | Wave Number|
|       00 00 | 0000 000a | Tone Switch                     0 - 1   (OFF,ON)   | 	+———————————————————————————————————————————————————————————+
|       00 01 | 0000 0000 | Wave Group Type                 0                  | 	|A001-254  |        0         |        1       |     0 - 253|
|       00 02 | 0000 00aa | Wave Group ID                   0 - 3              | 	|B001-251  |        0         |        2       |     0 - 250|
|#      00 03 | 0000 aaaa | Wave Number                     0 - 253            | 	|C001-236  |        0         |        3       |     0 - 235|
|             | 0000 bbbb |                                         (001 - 254)| 	+———————————————————————————————————————————————————————————+
|       00 05 | 0000 00aa | Wave Gain                       0 - 3              | -6, 0, +6, +12
|       00 06 | 0000 aaaa | Bend Range                      0 - 12             |
|       00 07 | 000a aaaa | Mute Group                      0 - 31 (OFF,1 - 31)|
|       00 08 | 0000 000a | Envelope Mode                   0 - 1              | NO-SUS, SUSTAIN
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 09 | 0aaa aaaa | JV-2080 Volume Control Switch   0 - 1   (OFF,ON)   |
|       00 0A | 0aaa aaaa | JV-2080 Hold-1 Control Switch   0 - 1   (OFF,ON)   |
|       00 0B | 0aaa aaaa | JV-2080 Pan Control Switch      0 - 2              | OFF, CONTINUOUS, KEY-ON
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 0C | 0aaa aaaa | Coarse Tune                     0 - 120 (-60 - +60)|
|       00 0D | 0aaa aaaa | Fine Tune                       0 - 100 (-50 - +50)|
|       00 0E | 000a aaaa | Random Pitch Depth              0 - 30             | 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200
|       00 0F | 000a aaaa | Pitch Envelope Depth            0 - 24  (-12 - +12)|
|       00 10 | 0aaa aaaa | Pitch Envelope Velocity Sens    0 - 125            | -100 - +150
|       00 11 | 0000 aaaa | Pitch Envelope Velocity Time1   0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 12 | 0aaa aaaa | Pitch Envelope Time 1           0 - 127            |
|       00 13 | 0aaa aaaa | Pitch Envelope Time 2           0 - 127            |
|       00 14 | 0aaa aaaa | Pitch Envelope Time 3           0 - 127            |
|       00 15 | 0aaa aaaa | Pitch Envelope Time 4           0 - 127            |
|       00 16 | 0aaa aaaa | Pitch Envelope Level 1          0 - 126 (-63 - +63)|
|       00 17 | 0aaa aaaa | Pitch Envelope Level 2          0 - 126 (-63 - +63)|
|       00 18 | 0aaa aaaa | Pitch Envelope Level 3          0 - 126 (-63 - +63)|
|       00 19 | 0aaa aaaa | Pitch Envelope Level 4          0 - 126 (-63 - +63)|
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 1A | 0000 0aaa | Filter Type                     0 - 4              |  OFF, LPF, BPF, HPF, PKG
|       00 1B | 0aaa aaaa | Cutoff Frequency                0 - 127            |
|       00 1C | 0aaa aaaa | Resonance                       0 - 127            |
|       00 1D | 0aaa aaaa | Resonance Velocity Sens         0 - 125            | -100 - +150
|       00 1E | 0aaa aaaa | Filter Envelope Depth           0 - 126 (-63 - +63)|
|       00 1F | 0aaa aaaa | Filter Envelope Velocity Sens   0 - 125            | -100 - +150
|       00 20 | 0000 aaaa | Filter Envelope Velocity Time1  0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 21 | 0aaa aaaa | Filter Envelope Time 1          0 - 127            |
|       00 22 | 0aaa aaaa | Filter Envelope Time 2          0 - 127            |
|       00 23 | 0aaa aaaa | Filter Envelope Time 3          0 - 127            |
|       00 24 | 0aaa aaaa | Filter Envelope Time 4          0 - 127            |
|       00 25 | 0aaa aaaa | Filter Envelope Level 1         0 - 127            |
|       00 23 | 0aaa aaaa | Filter Envelope Level 2         0 - 127            |
|       00 27 | 0aaa aaaa | Filter Envelope Level 3         0 - 127            |
|       00 28 | 0aaa aaaa | Filter Envelope Level 4         0 - 127            |
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 29 | 0aaa aaaa | Tone Level                      0 - 127            |
|       00 2A | 0aaa aaaa | Amp Envelope Velocity Sens      0 - 125            | -100 - +150
|       00 2B | 0000 aaaa | Amp Envelope Velocity Time1     0 - 14             | -100, -70, -50, -40, -30, -20, -10, 0, +10, +20, +30, +40, +50, +70, +100
|       00 2C | 0aaa aaaa | Amp Envelope Time 1             0 - 127            |
|       00 2D | 0aaa aaaa | Amp Envelope Time 2             0 - 127            |
|       00 2E | 0aaa aaaa | Amp Envelope Time 3             0 - 127            |
|       00 2F | 0aaa aaaa | Amp Envelope Time 4             0 - 127            |
|       00 30 | 0aaa aaaa | Amp Envelope Level 1            0 - 127            |
|       00 31 | 0aaa aaaa | Amp Envelope Level 2            0 - 127            |
|       00 32 | 0aaa aaaa | Amp Envelope Level 3            0 - 127            |
|       00 33 | 0aaa aaaa | Tone Pan                        0 - 127 (L64 - 63R)|
|       00 34 | 00aa aaaa | Random Pan Switch               0,63    (OFF,ON)   |
|       00 35 | 0aaa aaaa | Alternate Pan Depth             1 - 127 (L63 - 63R)|
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 36 | 0000 00aa | M-FX Switch                     0 - 3              | OFF, ON, Reserved, Reserved
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 37 | 0aaa aaaa | JV-2080 Mix/EFX Send Level      0 - 127            |
|—————————————+———————————+————————————————————————————————————————————————————|
|       00 38 | 0aaa aaaa | Delay Send Level                0 - 127            |
|       00 39 | 0aaa aaaa | Reverb Send Level               0 - 127            |
|—————————————+————————————————————————————————————————————————————————————————|
| Total size  | 00 00 00 3A                                                    |
+——————————————————————————————————————————————————————————————————————————————+
*/

CopyableTone::CopyableTone() :
	m_partOrigin(AllParts::PartR),
	m_toneNumberOrigin(0)
{
	initPointerArrays();
}

CopyableTone::CopyableTone(PatchToneBlock* patchToneToCopyFrom) : CopyableTone()
{
	m_partOrigin = (AllParts)patchToneToCopyFrom->getPart();
	m_toneNumberOrigin = (int)patchToneToCopyFrom->getTone();

	for (uint8 i = 0; i < m_synthPatchToneValuePointers.size(); i++)
	{
		*(m_synthPatchToneValuePointers[i]) = patchToneToCopyFrom->getRawDataByte(i);
	}
}

CopyableTone::CopyableTone(RhythmNoteBlock* rhythmToneToCopyFrom) : CopyableTone()
{
	m_partOrigin = PartR;
	m_toneNumberOrigin = (int)rhythmToneToCopyFrom->getKey();

	for (uint8 i = 0; i < m_rhyNoteTonePointers.size(); i++)
	{
		*(m_rhyNoteTonePointers[i]) = rhythmToneToCopyFrom->getRawDataByte(i);
	}
}

CopyableTone::CopyableTone(const SyxMsg* sysExOfToneToLoad) : CopyableTone()
{
}

void CopyableTone::initPointerArrays()
{
	m_synthPatchToneValuePointers.add(&m_ToneSwitch);
	m_synthPatchToneValuePointers.add(&m_WaveGroupType);
	m_synthPatchToneValuePointers.add(&m_WaveGroupID);
	m_synthPatchToneValuePointers.add(&m_WaveNumberMSB);
	m_synthPatchToneValuePointers.add(&m_WaveNumberLSB);
	m_synthPatchToneValuePointers.add(&m_WaveGain);
	m_synthPatchToneValuePointers.add(&m_FXMSwitch);
	m_synthPatchToneValuePointers.add(&m_FXMColor);
	m_synthPatchToneValuePointers.add(&m_FXMDepth);
	m_synthPatchToneValuePointers.add(&m_JV2080DelayMode);
	m_synthPatchToneValuePointers.add(&m_JV2080DelayTime);
	m_synthPatchToneValuePointers.add(&m_VelocityCrossFade);
	m_synthPatchToneValuePointers.add(&m_VelocityRangeLower);
	m_synthPatchToneValuePointers.add(&m_VelocityRangeUpper);
	m_synthPatchToneValuePointers.add(&m_KeyboardRangeLower);
	m_synthPatchToneValuePointers.add(&m_KeyboardRangeUpper);
	m_synthPatchToneValuePointers.add(&m_JV2080RedamperControlSwitch);
	m_synthPatchToneValuePointers.add(&m_JV2080VolumeControlSwitch);
	m_synthPatchToneValuePointers.add(&m_JV2080Hold1ControlSwitch);
	m_synthPatchToneValuePointers.add(&m_JV2080PitchBendControlSwit);
	m_synthPatchToneValuePointers.add(&m_JV2080PanControlSwitch);
	m_synthPatchToneValuePointers.add(&m_ModulationDestination1);
	m_synthPatchToneValuePointers.add(&m_ModulationDepth1);
	m_synthPatchToneValuePointers.add(&m_ModulationDestination2);
	m_synthPatchToneValuePointers.add(&m_ModulationDepth2);
	m_synthPatchToneValuePointers.add(&m_ModulationDestination3);
	m_synthPatchToneValuePointers.add(&m_ModulationDepth3);
	m_synthPatchToneValuePointers.add(&m_ModulationDestination4);
	m_synthPatchToneValuePointers.add(&m_ModulationDepth4);
	m_synthPatchToneValuePointers.add(&m_PitchBendDestination1);
	m_synthPatchToneValuePointers.add(&m_PitchBendDepth1);
	m_synthPatchToneValuePointers.add(&m_PitchBendDestination2);
	m_synthPatchToneValuePointers.add(&m_PitchBendDepth2);
	m_synthPatchToneValuePointers.add(&m_PitchBendDestination3);
	m_synthPatchToneValuePointers.add(&m_PitchBendDepth3);
	m_synthPatchToneValuePointers.add(&m_PitchBendDestination4);
	m_synthPatchToneValuePointers.add(&m_PitchBendDepth4);
	m_synthPatchToneValuePointers.add(&m_AftertouchDestination1);
	m_synthPatchToneValuePointers.add(&m_AftertouchDepth1);
	m_synthPatchToneValuePointers.add(&m_AftertouchDestination2);
	m_synthPatchToneValuePointers.add(&m_AftertouchDepth2);
	m_synthPatchToneValuePointers.add(&m_AftertouchDestination3);
	m_synthPatchToneValuePointers.add(&m_AftertouchDepth3);
	m_synthPatchToneValuePointers.add(&m_AftertouchDestination4);
	m_synthPatchToneValuePointers.add(&m_AftertouchDepth4);
	m_synthPatchToneValuePointers.add(&m_LFO1Waveform);
	m_synthPatchToneValuePointers.add(&m_LFO1KeySync);
	m_synthPatchToneValuePointers.add(&m_LFO1Rate);
	m_synthPatchToneValuePointers.add(&m_LFO1Offset);
	m_synthPatchToneValuePointers.add(&m_LFO1DelayTime);
	m_synthPatchToneValuePointers.add(&m_LFO1FadeMode);
	m_synthPatchToneValuePointers.add(&m_LFO1FadeTime);
	m_synthPatchToneValuePointers.add(&m_LFO1TempoSync);
	m_synthPatchToneValuePointers.add(&m_LFO2Waveform);
	m_synthPatchToneValuePointers.add(&m_LFO2KeySync);
	m_synthPatchToneValuePointers.add(&m_LFO2Rate);
	m_synthPatchToneValuePointers.add(&m_LFO2Offset);
	m_synthPatchToneValuePointers.add(&m_LFO2DelayTime);
	m_synthPatchToneValuePointers.add(&m_LFO2FadeMode);
	m_synthPatchToneValuePointers.add(&m_LFO2FadeTime);
	m_synthPatchToneValuePointers.add(&m_LFO2TempoSync);
	m_synthPatchToneValuePointers.add(&m_CoarseTune);
	m_synthPatchToneValuePointers.add(&m_FineTune);
	m_synthPatchToneValuePointers.add(&m_RandomPitchDepth);
	m_synthPatchToneValuePointers.add(&m_PitchKeyfollow);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeDepth);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeVelocitySens);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeVelocityTime1);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeVelocityTime4);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeTimeKeyfollow);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeTime1);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeTime2);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeTime3);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeTime4);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeLevel1);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeLevel2);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeLevel3);
	m_synthPatchToneValuePointers.add(&m_PitchEnvelopeLevel4);
	m_synthPatchToneValuePointers.add(&m_PitchLFO1Depth);
	m_synthPatchToneValuePointers.add(&m_PitchLFO2Depth);
	m_synthPatchToneValuePointers.add(&m_FilterType);
	m_synthPatchToneValuePointers.add(&m_CutoffFrequency);
	m_synthPatchToneValuePointers.add(&m_CutoffKeyfollow);
	m_synthPatchToneValuePointers.add(&m_Resonance);
	m_synthPatchToneValuePointers.add(&m_ResonanceVelocitySens);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeDepth);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeVelocityCurve);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeVelocitySens);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeVelocityTime1);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeVelocityTime4);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeTimeKeyfollow);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeTime1);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeTime2);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeTime3);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeTime4);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeLevel1);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeLevel2);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeLevel3);
	m_synthPatchToneValuePointers.add(&m_FilterEnvelopeLevel4);
	m_synthPatchToneValuePointers.add(&m_FilterLFO1Depth);
	m_synthPatchToneValuePointers.add(&m_FilterLFO2Depth);
	m_synthPatchToneValuePointers.add(&m_ToneLevel);
	m_synthPatchToneValuePointers.add(&m_BiasDirection);
	m_synthPatchToneValuePointers.add(&m_BiasPoint);
	m_synthPatchToneValuePointers.add(&m_BiasLevel);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeVelocityCurve);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeVelocitySens);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeVelocityTime1);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeVelocityTime4);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeTimeKeyfollow);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeTime1);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeTime2);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeTime3);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeTime4);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeLevel1);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeLevel2);
	m_synthPatchToneValuePointers.add(&m_AmpEnvelopeLevel3);
	m_synthPatchToneValuePointers.add(&m_AmpLFO1Depth);
	m_synthPatchToneValuePointers.add(&m_AmpLFO2Depth);
	m_synthPatchToneValuePointers.add(&m_TonePan);
	m_synthPatchToneValuePointers.add(&m_PanKeyfollow);
	m_synthPatchToneValuePointers.add(&m_RandomPanSwitch);
	m_synthPatchToneValuePointers.add(&m_AlternatePanDepth);
	m_synthPatchToneValuePointers.add(&m_PanLFO1Depth);
	m_synthPatchToneValuePointers.add(&m_PanLFO2Depth);
	m_synthPatchToneValuePointers.add(&m_MFXSwitch);
	m_synthPatchToneValuePointers.add(&m_JV2080MixEFXSendLevel);
	m_synthPatchToneValuePointers.add(&m_DelaySendLevel);
	m_synthPatchToneValuePointers.add(&m_ReverbSendLevel);

	m_rhyNoteTonePointers.add(&m_ToneSwitch);
	m_rhyNoteTonePointers.add(&m_WaveGroupType);
	m_rhyNoteTonePointers.add(&m_WaveGroupID);
	m_rhyNoteTonePointers.add(&m_WaveNumberMSB);
	m_rhyNoteTonePointers.add(&m_WaveNumberLSB);
	m_rhyNoteTonePointers.add(&m_WaveGain);
	m_rhyNoteTonePointers.add(&m_BendRange);
	m_rhyNoteTonePointers.add(&m_MuteGroup);
	m_rhyNoteTonePointers.add(&m_EnvelopeMode);
	m_rhyNoteTonePointers.add(&m_JV2080VolumeControlSwitch);
	m_rhyNoteTonePointers.add(&m_JV2080Hold1ControlSwitch);
	m_rhyNoteTonePointers.add(&m_JV2080PanControlSwitch);
	m_rhyNoteTonePointers.add(&m_CoarseTune);
	m_rhyNoteTonePointers.add(&m_FineTune);
	m_rhyNoteTonePointers.add(&m_RandomPitchDepth);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeDepth);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeVelocitySens);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeVelocityTime1);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeTime1);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeTime2);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeTime3);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeTime4);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeLevel1);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeLevel2);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeLevel3);
	m_rhyNoteTonePointers.add(&m_PitchEnvelopeLevel4);
	m_rhyNoteTonePointers.add(&m_FilterType);
	m_rhyNoteTonePointers.add(&m_CutoffFrequency);
	m_rhyNoteTonePointers.add(&m_Resonance);
	m_rhyNoteTonePointers.add(&m_ResonanceVelocitySens);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeDepth);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeVelocitySens);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeVelocityTime1);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeTime1);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeTime2);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeTime3);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeTime4);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeLevel1);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeLevel2);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeLevel3);
	m_rhyNoteTonePointers.add(&m_FilterEnvelopeLevel4);
	m_rhyNoteTonePointers.add(&m_ToneLevel);
	m_rhyNoteTonePointers.add(&m_AmpEnvelopeVelocitySens);
	m_rhyNoteTonePointers.add(&m_AmpEnvelopeVelocityTime1);
	m_rhyNoteTonePointers.add(&m_AmpEnvelopeTime1);
	m_rhyNoteTonePointers.add(&m_AmpEnvelopeTime2);
	m_rhyNoteTonePointers.add(&m_AmpEnvelopeTime3);
	m_rhyNoteTonePointers.add(&m_AmpEnvelopeTime4);
	m_rhyNoteTonePointers.add(&m_AmpEnvelopeLevel1);
	m_rhyNoteTonePointers.add(&m_AmpEnvelopeLevel2);
	m_rhyNoteTonePointers.add(&m_AmpEnvelopeLevel3);
	m_rhyNoteTonePointers.add(&m_TonePan);
	m_rhyNoteTonePointers.add(&m_RandomPanSwitch);
	m_rhyNoteTonePointers.add(&m_AlternatePanDepth);
	m_rhyNoteTonePointers.add(&m_MFXSwitch);
	m_rhyNoteTonePointers.add(&m_JV2080MixEFXSendLevel);
	m_rhyNoteTonePointers.add(&m_DelaySendLevel);
	m_rhyNoteTonePointers.add(&m_ReverbSendLevel);
}

CopyableTone::~CopyableTone()
{

}

// allowed toneNumber values are Tone1 = 0x1000, Tone2 = 0x1200, Tone3 = 0x1400, Tone4 = 0x1600 for synth parts or 35..98 for rhythm part
void CopyableTone::copyTo(AllParts part, int toneNumber)
{
	if (grooveboxMemory == nullptr) return;

	if(part == PartR)
	{
		if (toneNumber >= 35 && toneNumber <= 98)
		{
			if (RhythmSetBlock* rhythmSetBlock = grooveboxMemory->getRhythmSetBlock())
			{
				if (RhythmNoteBlock* rhythmNoteBlock = rhythmSetBlock->getRhythmNoteBlockPtr((uint8)toneNumber))
				{
					for (int i = 0; i < m_rhyNoteTonePointers.size(); i++)
					{
						if (i == A_RHY_WAVENUMBERMSB) // wave number: combine msb | lsb
						{
							if (Parameter* param = rhythmNoteBlock->getParameter(i))
							{
								param->setValue(m_WaveNumberMSB << 4 | m_WaveNumberLSB, Parameter::GuiWidget);
							}
							i++; // skip LSB
						}
						else if (i == A_RHY_WAVENUMBERLSB) {} // should be skipped
						else if (i == A_RHY_COARSETUNE && this->m_partOrigin != PartR) // convert synth coarse tune value (+/-48) to rhy coarse tune value (+/-60)
						{
							if (Parameter* param = rhythmNoteBlock->getParameter(i))
							{
								param->setValue((uint8)((int)m_CoarseTune - 48 + 60), Parameter::GuiWidget);
							}
						}
						else // copy by default
						{
							if (Parameter* param = rhythmNoteBlock->getParameter(i))
							{
								param->setValue(*(m_rhyNoteTonePointers[i]), Parameter::GuiWidget);
							}
						}
					}
				}
			}
		}
	}
	else if (toneNumber == Tone1 || toneNumber == Tone2 || toneNumber == Tone3 || toneNumber == Tone4)
	{
		if (SynthPatchesBlock* synthPatchesBlock = grooveboxMemory->getSynthPatchesBlock())
		{
			if (PatchPartBlock* patchPartBlock = synthPatchesBlock->getPatchPartBlockPtr((SynthParts) part))
			{
				if (PatchToneBlock* patchToneBlock = patchPartBlock->getPatchToneBlockPtr((Tone)toneNumber))
				{
					for (int i = 0; i < m_synthPatchToneValuePointers.size(); i++)
					{
						if (i == A_PATCH_WAVENUMBERMSB) // wave number: combine msb | lsb
						{
							if (Parameter* param = patchToneBlock->getParameter(i))
							{
								param->setValue(m_WaveNumberMSB << 4 | m_WaveNumberLSB, Parameter::GuiWidget);
							}
							i++; // skip LSB
						}
						else if (i == A_PATCH_WAVENUMBERLSB) {} // should be skipped
						else if (i == A_PATCH_COARSETUNE && this->m_partOrigin == PartR) // convert rhy coarse tune value (+/-60) to synth coarse tune value (+/-48)
						{
							if (Parameter* param = patchToneBlock->getParameter(i))
							{
								param->setValue(jlimit<uint8>(0, 96, (uint8)((int)m_CoarseTune - 60 + 48)), Parameter::GuiWidget);
							}
						}
						else // copy by default
						{
							if (Parameter* param = patchToneBlock->getParameter(i))
							{
								param->setValue(*(m_synthPatchToneValuePointers[i]), Parameter::GuiWidget);
							}
						}
					}
				}
			}
		}
	}
}

void CopyableTone::swapWith(AllParts part, int toneNumber)
{
	if (grooveboxMemory == nullptr) return;

	// swap with destination part r
	if (part == PartR)
	{
		if (toneNumber >= 35 && toneNumber <= 98)
		{
			if (RhythmSetBlock* rhythmSetBlock = grooveboxMemory->getRhythmSetBlock())
			{
				if (RhythmNoteBlock* rhythmNoteBlockDest = rhythmSetBlock->getRhythmNoteBlockPtr((uint8)toneNumber))
				{
					// get destination into temp
					ScopedPointer<CopyableTone> destinationOldState = new CopyableTone(rhythmNoteBlockDest);	
					// copy this to destination
					this->copyTo(part, toneNumber);
					// copy old state from temp to origin
					destinationOldState->copyTo(this->m_partOrigin, this->m_toneNumberOrigin);
				}
			}
		}
	}
	// swap with synth destination
	else if (toneNumber == Tone1 || toneNumber == Tone2 || toneNumber == Tone3 || toneNumber == Tone4)
	{
		if (SynthPatchesBlock* synthPatchesBlock = grooveboxMemory->getSynthPatchesBlock())
		{
			if (PatchPartBlock* patchPartBlock = synthPatchesBlock->getPatchPartBlockPtr((SynthParts)part))
			{
				if (PatchToneBlock* patchToneBlock = patchPartBlock->getPatchToneBlockPtr((Tone)toneNumber))
				{
					// get destination into temp
					ScopedPointer<CopyableTone> destinationOldState = new CopyableTone(patchToneBlock);
					// copy this to destination
					this->copyTo(part, toneNumber);
					// copy old state from temp to origin
					destinationOldState->copyTo(this->m_partOrigin, this->m_toneNumberOrigin);
				}
			}
		}
	}
}