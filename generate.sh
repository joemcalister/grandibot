#!/usr/bin/env bash

# make sure we are in the directory
cd bot
#cd /var/www/api.joemcalister.com/html/drawingbot2/bot

# capture the output which is the tweet text content
formula="$(./drawingbot2)"

# move output to the correct folder
mv output.png ./../twitter/

# change into folder and run upload script
cd ./../twitter
php upload.php "$formula"

# move to latest image for website
mv output.png ./../latest/image.png