<?php
if (defined("G") == true) {
    echo 1;
} else {
    echo 0;
}
echo "\n";
define( "G", "hellword" );
if (defined("G") == true) {
    echo 1;
} else {
    echo 0;
}