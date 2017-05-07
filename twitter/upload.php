<?php
    // import api
    require_once('TwitterAPIExchange.php');
    require_once('credentials/cred.php');

    // grab the image file from the current directory
    $file = file_get_contents(getcwd().'/output.png');

    // base 64 encode it
    $image = base64_encode($file);

    // determine url for api
    $url = "https://upload.twitter.com/1.1/media/upload.json";
    $method = "POST";
    $params = array(
        "media_data" => $image,
    );

    // init twitter api
    $twitter = new TwitterAPIExchange($settings);

    // build request and send
    $json = $twitter
        ->buildOauth($url, $method)
        ->setPostfields($params)
        ->performRequest();

    // get returns
    $returns = json_decode($json);

    // grab media id
    $mediaid = $returns->media_id_string;

    // post with attached media id
    $url = 'https://api.twitter.com/1.1/statuses/update.json';
    $requestMethod = 'POST';
    $postfields = array(
        'media_ids' => $mediaid,
        'status' => $argv[1] );

    // post the tweet!
    $twitter->buildOauth($url, $requestMethod)
        ->setPostfields($postfields)
        ->performRequest();

    echo "Tweet posted!\n";

?>