<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <meta name="keywords" content="HTML,XHTML,PHP,网页创建">
    <meta name="description" content="SW智能库存管理系统">
    <meta name="author" content="Zam">
    <title>SW智能库存管理系统</title>
    <link type="text/css" rel="stylesheet" href="css/style.css" />
    <script type="text/javascript" src="js/jquery-1.8.3.min.js"></script>
    <script type="text/javascript" src="js/menu.js"></script>
</head>
<body>
    <?php  
    // 1.导入配置文件
    require "dbconfig.php";
    // 2. 连接mysql
    $link = mysqli_connect(HOST,USER,PASS) or die("提示：数据库连接失败！");
    // 选择数据库
    mysqli_select_db($link,DBNAME);
    // 编码设置
    mysqli_set_charset($link,'utf8');
?>
</body>
</html>