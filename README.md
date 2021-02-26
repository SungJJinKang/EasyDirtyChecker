# EasyDirtyChecker

Each Receivers will receive dirty value from Sender ( Only One ).    
And Reveivers will maintain dirty value until they reset dirty themself 

```
          Sender      Receiver   
        (Only One)   (Multiple)   
Frame 1     X            X   

Frame 2     O            O ( Receive Dirty )   

Frame 3     X            O ( Not Reset )   

Frame 4     X            O   

Frame 5     X            X ( Reset Dirty )   
```
