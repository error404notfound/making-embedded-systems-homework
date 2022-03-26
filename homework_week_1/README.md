# Homework - Exercise 1

<img align="right" width = 50% src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_1/Assets/images/Introduction%20and%20Description%20.png">
<p>
Sense stones are an interactive set of irregular river stones that encourage calming play and exploration through haptic, light, and audio output.

Utilizing BLE, an accelerometer, a captive touch grid, and acting as a tactile button, the way the stones are played with changes the output they produce.

Initial setup requires interaction with a BLE-connected app. After that, users can switch modes through gestures with the stones themselves or within the app.

*Some possible examples.*

### Modes to target stress and anxiety

- Lead breathing exercises
- Sleep ritual - light and haptics guide users through the 8/5 breathing timer
- Relaxation timer

### Occupational therapy tool

- Haptic and lights display the difference between soft and hard touches, i.e., a light stroke that doesn't activate the tactile button would have a soft blue light response and a "purr" from the motors.
- Stimming toy (  data logged in this mode to help identify stress triggers, i.e.  user A's usage in stim mode increases at a particular time, which may indicate an external trigger that occurs around this time )
- Grouping by color or size order
- Reaction button play - as each lights up, the stone is tapped.
- Yes and No buttons.
- Hide and seek
- Record the interaction data for later examination when used away from a BLE connection.

### Open play

A Musical example.

Initially, the stones are laid out in a line. Interacting with the stones changes the audio and light output. Moving the stones closer to each changes the note of the Audio sample played, picking the stones up changes the volume of the audio,  quick movements with the stones like shaking will increase the beat,

*Once the framework is built, new modes or "sessions" could be developed to suit different needs, either for single stones or sets.*
<p align="center">
  <img  src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_1/Assets/images/20220324_215846.jpg">
  <i>Exploded view of sense stone</i>
</p>

## Hardware Block Diagram

<p></p>
<p align="center">
  <img  src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_1/Assets/diagrams/Homework%20-%201-Hardware%20Block.drawio.png">
  <i>Version 4</i>
</p>

## Software Block Diagram
<p></p>
<p align="center">
  <img  src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_1/Assets/diagrams/Homework%20-%201-Software%20Block.drawio.png">
  <i>Version 5</i>
</p>

## Hireachy of Control

<p></p>
<p align="center">
  <img  src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_1/Assets/diagrams/Homework%20-%201-HoC.drawio.png">
  <i>Version 5</i>
</p>
