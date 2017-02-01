# Grandibot - A generative art twitter bot based on Luigi Guido Grandi's formula.
![Grandibot](https://joemcalister.com/img/git/grandibot.jpg)

## How does it work?
The shell script generate.sh is called every other hour by my crontab. This script generates an image using the compiled drawingbot2 located in the bot folder (written in C++). It then moves the image to the twitter directory where the php script upload.php uploads and tweets the image. I use OpenCV 3.0 to draw the diagrams.
