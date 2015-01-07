Juronstruktor
===========
The Juronstruktor is a basic sample player with sequencer and effects based on the Dekrispator previous project.
25 samples are loaded in flash memory. These samples are recordings of syllables of french dirty words ("jurons" in french) said by me.
The result is a funny talking and swearing machine that you can control.
Of course you can load your own samples but the task is a bit tedious. I've used a very usefull tool called WaveToCode to produce the c files of each samples from wav files.

Demo video is here :
http://youtu.be/spdb0K8gsQM?list=UUKbBi-lO1MtBKqolWJseSkQ

- - - -

**Usage**

Flash your board with "Juronstruktor.hex" (in Release folder).
Connect an USB MIDI controller (like Korg NanoKontrol...) to the board's micro USB connector and control the machine.
The MIDI mapping of the synth controls are more or less in MIDI_mapping.ods file. I nearly used the factory settings of Korg NanoKontrol V1 (some momentary/toggle buttons modified). The blue LED indicates midi activity.
Actual MIDI implementation is in midi_interface.c file, in function MIDI_Decode().

- - - -

**Juronstruktor features** :

* 2 voice sample player with pitch control
* 16 step sequencer with random samples fuction
* 2 parallel filters LP/BP/HP with LFOs
* Effects :
* Echo
* Chorus/Flanger
* Phaser
* random FX patch generator
* 32kHz samplerate

- - - -

**Building from source :**

I've used (on Windows Vista):

* Eclipse Luna
* GNU ARM plugin for Eclipse
* Yagarto tools for make, rm, ...
* GNU Tools for ARM Embedded Processors (gcc 4.9)
* STM32 ST-LINK Utility for flashing the microcontroller

- - - 
  
