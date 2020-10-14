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
        <style>.error {color: #FF0000;}</style>
    </head>
    <body>
        <div class="top"></div>
        <div id="header">
	<div class="logo"><a href="http://localhost/SW-SmartWarehouse/index.php">SW智能库存管理系统</a></div>
        <div class="navigation">
		<ul>
		 	<?php require "Host-set.php";//导入配置文件 ?>
                    <?php
                    //判断是否为游客
                    if($_COOKIE['CUSER']==''||$_COOKIE['CPASS']==''||$_COOKIE['DB']==''||$_COOKIE['SID']=='')
                    {
                    $username='游客';
                    }
                    else{
                    //连接mysql
                    $link = mysqli_connect(HOST,$_COOKIE['CUSER'],$_COOKIE['CPASS']) or die("<center><script>alert('数据库连接失败！');</script></center>");
                    // 选择数据库
                    mysqli_select_db($link,$_COOKIE['DB']);
                    // 编码设置
                    mysqli_set_charset($link,'utf8');
                    // 创建连接
                    $conn = new mysqli(HOST,$_COOKIE['CUSER'],$_COOKIE['CPASS'],$_COOKIE['DB']);
                    // 检测连接
                    if ($conn->connect_error) {
                    die("<center><script>alert('数据库连接失败！');</script></center>");
                    } 
                    $useri=$_COOKIE['SID'];
                    // 获取用户名
                    $query="SELECT staffname FROM staffmember WHERE staffID='$useri'";
                    $result = $conn->query($query);
                    if (!$result) {
                    die("<center><script>alert('数据读取失败！');</script></center>");
                    }
                    $rows=$result->num_rows;
                    $username=$result->fetch_assoc()['staffname'];
                    }
                    
                    ?>
		 	<li><h3>欢迎您！</h3></li>
			<li><a href="http://localhost/SW-SmartWarehouse/information.php"><h3><?php echo $username;?></h3></a></li>
			<li><a href="http://localhost/SW-SmartWarehouse/passchange.php"><h3>修改密码</h3></a></li>
			<li><a href="http://localhost/SW-SmartWarehouse/setting.php"><h3>设置</h3></a></li>
			<li><a href="http://localhost/SW-SmartWarehouse/quit.php"><h3>退出登录</h3></a></li>
		</ul>
	</div>
        </div>
        <div id="content">
        <div class="main">
            <br>
            <br>
            <br>
            <center><h2>正在开发中...</h2></center>
            <center><h2>敬请期待！</h2></center>
            <br><br><br>
            <center><a href="http://localhost/SW-SmartWarehouse/AAA_createDATA.php"><h2>插入数据</h2></a></center>
            <center><a href="http://localhost/SW-SmartWarehouse/AAA_createFORM.php"><h2>插入表单</h2></a></center>
            <?php
            
            ?>
	</div>
        </div>
        <div class="bottom"></div>
        <div id="footer"><p>Copyright© 2019 版权所有 SW智能库存管理系统团队 V1.2.1 <a href="http://localhost/SW-SmartWarehouse/lianxi.php"><font color="#00FFFF">联系我们</font></a></p></div>
        <script>navList(12);</script>
    </body>
</html>
