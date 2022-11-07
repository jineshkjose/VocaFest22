# importing vlc module

#How to install the VLC module?

#In order to install the VLC module in Python, we will use the pip installer following the command shown below:

#Syntax:    $ pip install python-vlc  
import vlc

# importing time module
import time


# creating vlc media player object
#media_player = vlc.MediaPlayer()

# setting full screen status
#media_player.media_player.set_fullscreen(True)

vlc_instance = vlc.Instance()
player = vlc_instance.media_player_new()
player.set_fullscreen(True)



# media object
media = vlc.Media("001.mp4")




# setting media to the media player
player.set_media(media)


    

# start playing video
player.play()


# wait so the video can be played for 5 seconds
# irrespective for length of video
time.sleep(180)



player.stop()


