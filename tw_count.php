#!/usr/bin/php
<?php
$screen_name = $argv[1];
$url = "http://api.twitter.com/1/statuses/user_timeline.json?screen_name={$screen_name}&count=1";
$json = @json_decode(@file_get_contents($url));
echo $json[0]->user->statuses_count;
