#!/usr/bin/env bash

cd bot
./drawingbot2
mv output.png ./../twitter/
cd ./../twitter
php upload.php
rm output.png