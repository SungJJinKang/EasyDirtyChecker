# EasyDirtyChecker

## HOW WORKS?

```
          Sender      Receiver   
        (Only One)   (Multiple)   
Frame 1     X            X   

Frame 2     O            O ( Receive Dirty )   

Frame 3     X            O ( Not Reset )   

Frame 4     X            O   

Frame 5     X            X ( Reset Dirty )   
```


Put DirtySender at Sender Class, Put DirtyReceiver at Receiver Class.     
You can add multiple receiver to DirtySender ( Use DirtyReceiver::SetDirtySender )      
You don't need remove receiver from DirtySender's receiver List when Receiver class is destructed.     

Each Receivers will receive dirty value from Sender ( Only One ).       
And Reveivers will maintain dirty value until they reset dirty themself       
You can receiver dirty value to your own LocalDirty variable ( use AddLocalIsDirtyVariable )     

I don't recommend MainIsDirtyVariable. use your own dirty variable and add it to Receiver object.   

Why use LocalDirty Class???    
if support plain bool Local Dirty Variable, Programmers can foget to reset dirty variable    
So I force programmers to get Dirty value only through GetIsDirtyMain(bool clearDirty)

