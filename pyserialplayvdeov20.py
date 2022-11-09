# importing vlc module

#How to install the VLC module?

#In order to install the VLC module in Python, we will use the pip installer following the command shown below:

#Syntax:    $ pip install python-vlc  
import vlc

# importing time module
import time




import serial

#pip install keyboard
#import keyboard

    
    


serialcomm = serial.Serial('/dev/ttyACM0', 9600)

serialcomm.timeout = 1

while True:

    

    #if keyboard.is_pressed("q"):
        # Key was pressed
        #break
  
    strrec=serialcomm.readline().decode('ascii')
    strrec=strrec[0:2]
    print(strrec)

    if(strrec=="@a"):
        print("opt1")
        vlc_instance = vlc.Instance()
        player = vlc_instance.media_player_new()
        player.set_fullscreen(True)
        # media object
        media = vlc.Media("MOUTH.mp4")
        # setting media to the media player
        player.set_media(media)
        # start playing video
        player.play()
        # wait so the video can be played for 5 seconds
        # irrespective for length of video  IN SEC
        time.sleep(5)
        player.stop()
        
    elif(strrec=="@b"):
        print("opt2")
       
        vlc_instance = vlc.Instance()
        player = vlc_instance.media_player_new()
        player.set_fullscreen(True)
        # media object
        media = vlc.Media("BRAIN.mp4")
        # setting media to the media player
        player.set_media(media)
        # start playing video
        player.play()
        # wait so the video can be played for 5 seconds
        # irrespective for length of video
        time.sleep(5)
        player.stop()
    elif(strrec=="@c"):
        print("opt3")
        
        vlc_instance = vlc.Instance()
        player = vlc_instance.media_player_new()
        player.set_fullscreen(True)
        # media object
        media = vlc.Media("KIDNEY.mp4")
        # setting media to the media player
        player.set_media(media)
        # start playing video
        player.play()
        # wait so the video can be played for 5 seconds
        # irrespective for length of video
        time.sleep(5)
        player.stop()
    elif(strrec=="@d"):
        print("opt4")
        
        vlc_instance = vlc.Instance()
        player = vlc_instance.media_player_new()
        player.set_fullscreen(True)
        # media object
        media = vlc.Media("MOUTH.mp4")
        # setting media to the media player
        player.set_media(media)
        # start playing video
        player.play()
        # wait so the video can be played for 5 seconds
        # irrespective for length of video
        time.sleep(5)
        player.stop()
    elif(strrec=="@e"):
        print("opt5")
        
        vlc_instance = vlc.Instance()
        player = vlc_instance.media_player_new()
        player.set_fullscreen(True)
        # media object
        media = vlc.Media("HEART.mp4")
        # setting media to the media player
        player.set_media(media)
        # start playing video
        player.play()
        # wait so the video can be played for 5 seconds
        # irrespective for length of video
        time.sleep(5)
        player.stop()

serialcomm.close()





