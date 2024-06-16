<?php

$range = range($i = 32, $i << 2);

shuffle($range);

$map = [];
file_put_contents('vars', '<?php ###OwnKrypt!'.PHP_EOL);
foreach ($range as $i) {
    $map[chr($i)] = '$'.str_replace('1', 'O', decbin($i));
    file_put_contents('vars', $map[chr($i)].'=\'%'.dechex($i).'\';', FILE_APPEND);
}
file_put_contents('vars', '$_=\'urldecode\';'.PHP_EOL, FILE_APPEND);

$fns = ['json_encode', 'json_decode', 'urlencode', 'urldecode'];

for ($i = 0; $i < count($fns); $i++) {
    $map[$fn = $fns[$i]] = '$'.str_replace('1', 'O', decbin(130+$i));
    $fns[$i] = join('.', array_map(fn ($c)=> '$_('.$map[$c].')', str_split($fn)));
    file_put_contents('vars', $map[$fn].'='.$fns[$i].';', FILE_APPEND);
}
file_put_contents('vars', PHP_EOL, FILE_APPEND);

file_put_contents('vars', 'echo '.$map['urldecode'].'('.$map['urlencode'].'(\'Hotash\'));', FILE_APPEND);