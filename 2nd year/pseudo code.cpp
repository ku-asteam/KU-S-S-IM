# Protocol State Inference pseudo Code

Input : Message msg, Field_size fs, Buffer buf

buf = [sum(fs)]
state = False
while(msg):
    if msg.arrive():
        buf = [1] * msg.arrive_size()
        if buf.is_Full():
            state = True # Received
            break;
        else:
            state = False # Receiving
           
Output : state (True/False)
