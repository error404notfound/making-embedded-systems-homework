# Sensory stone subsystem

## description. 

The aim of this project would be to implement some of the functionality of the [Sensory stones]() project. 

  * implement shake to wake
  * implement cli 
     *  pass test data to the cli
     *  mimic commands that would be replicated over ble 
        * output accelerometor data
        * set game state  
     *  test perpiherlas
     
  * Gesture recognition utilising the accelerometor to set mode ( using edge impulse to generate model ) ( detect 3 modes ) 
  * Implement the breathing pattern trainer using LCD  for visual feedback. 
  * Sleep timer
  * Save user settings to non volitaile memeory
  
  ## hardware diagram
  ## circuit diagram
  ## software diagram
  ## State Table
  One of the functionalitys that I want to develope is the ablity to load state tables  ( from the CLI for example ) as a way to use the same hardware and software frame work for new modes. For this reason below is the Main state table for the stone as well as an example of a state table with in the Breathing trainer mode. 
