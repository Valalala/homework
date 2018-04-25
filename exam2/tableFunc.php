<html>
<head>
<title>ECE331Example</title>
</head>
<body>
<?php
        #$x=0;
        function makeTable($w, $h){
            echo "<table>";
            echo "<table border=\"1\">";
            for ($i=0;$i<$h;$i++) {
                echo "<tr>\n";
                for ($j=0;$j<$w;$j++){
                    $v = $i + $j*$h;
                    echo "<td>$v</td>\n";
                }
                echo "</tr>\n";
            }
            echo "</table>";
        }
        
        makeTable(5,4);
?>
</body>
</html>

