# Sensory stone subsystem

## description. 

The aim of this project would be to implement some of the functionality of the [Sensory stones]() project. 

  * Implement shake to wake ( using gyroscope) 
  * User button interrupt to switch to CLI mode
  * Gesture recognition utilising the accelerometor to set mode ( using edge impulse to generate model ) ( detect 3 modes ) 
  * Implement the breathing pattern trainer using LEDS  for visual feedback. 
  * Sleep timer
  * Save user settings to non volitaile memeory
  * Data logging to USB mass storage ( as proof of concept ) 
  * implement cli 
     *  pass test data to the cli
     *  mimic commands that would be replicated over ble 
        * log activity/session data
        * set game state table 
     *  test perpiherlas
     *  save to mass storage
     *  set user prefrences ( like choosing the colour of the light in breathing mode ) 
     

  
  ## hardware diagram
<img src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_4/assets/Stone-subsystem-Hardware%20Block.drawio.png"  border="10"/>

  ## circuit diagram
  ## software block diagram 
  <img src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_4/assets/stone_sub_system-Software%20Block.drawio.png"  border="10"/>
  
  ## Hirachey of control 
  
  <img src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_4/assets/stone_sub_system-HoC.drawio.png"  border="10"/>
  
  ## State Table
  One of the functionalitys that I want to develope is the ablity to load state tables  ( from the CLI for example ) as a way to use the same hardware and software frame work for new modes. For this reason below is the Main state table for the stone as well as an example of a state table with in the Breathing trainer mode. 
