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
	<div class="logo"><a href="http://localhost/SW-SmartWarehouse/homepage.php">SW智能库存管理系统</a></div>
        <div class="navigation">
		<ul>
		 	<li><h3>您好，请</h3></li>
			<li><a href="http://localhost/SW-SmartWarehouse/complogin.php"><h3>登录公司数据库</h3></a></li>
		</ul>
	</div>
        </div>
        <div id="content">
        <div class="main">
            <?php require "Host-set.php";//导入配置文件 ?>
            <?php
            // 定义变量并默认设置为空值
            $userErr = $passErr = $dbnameErr = "";
            $user = $pass = $dbname = "";

        if ($_SERVER["REQUEST_METHOD"] == "POST")
        {
            
            if (empty($_POST["dbname"]))
            {
            $dbnameErr = " 请输入数据库名称";
            }
            else
            {
            $dbname = test_input($_POST["dbname"]);
            }
            if (empty($_POST["user"]))
            {
            $userErr = " 请输入公司账户";
            }
            else
            {
            $user = test_input($_POST["user"]);
            }
    
            if (empty($_POST["pass"]))
            {
            $passErr = " 请输入账户密码";
            }
            else
            {
            $pass = test_input($_POST["pass"]);
            }
    
        }

        function test_input($data)
        {
            $data = trim($data);
            $data = stripslashes($data);
            $data = htmlspecialchars($data);
            return $data;
        }
            ?>
            
            <br>
            <br>
            <br>
            <center><h2>欢迎使用SW智能库存管理系统! 请登录贵公司数据库：</h2></center>
            <br>
            <center>
            <form name="login" method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
            <table width="509" border="0">
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>公司数据库名称：    </h3></td>
            <td width="104" height="60"><input type="text"name="dbname" size="20" value="<?php echo $dbname;?>"/><span class="error"><?php echo $dbnameErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>公司账户：    </h3></td>
            <td width="104" height="60"><input type="text"name="user" size="20" value="<?php echo $user;?>"/><span class="error"><?php echo $userErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>账&nbsp;&nbsp户&nbsp;&nbsp密&nbsp;&nbsp码：    </h3></td>
            <td width="104" height="60"><input type="text" name="pass" size="20" value="<?php echo $pass;?>"/><span class="error"><?php echo $passErr;?></span></td>
            </tr>
            <tr align="center" bgcolor="#FFFFFF">
                <td height="60" colspan="3"><input type="submit" name="sumbit" value="登录数据库" style="height:45px;width:85px;"/></td>
            </tr>
            </table>
            </form>
            </center><br>
            <center><h3><a href="http://localhost/SW-SmartWarehouse/company-signup.php">申请数据库</a></h3></center>
            <center><h3><a href="http://localhost/SW-SmartWarehouse/losepassword.php">忘记密码</a></h3></center>
            <center><?php
            //快捷登录
            if($_COOKIE['CUSER']!=''&&$_COOKIE['CPASS']!=''&&$_COOKIE['DB']!=''&&$_COOKIE['SID']!='')
            {
                ?><span class="error"><center><h3><a href="http://localhost/SW-SmartWarehouse/index.php">检测到您已登陆，点此快捷登录！</a></h3></center></span><?php
            }
            //防止未填写表单情况下，运行后续代码报错
            if($user==""||$pass==""||$dbname=="")
            {
            
            }
            else
            {   
            $link = mysqli_connect(HOST,$user,$pass) or die("<center><script>alert('账户或密码错误！');</script></center>");
            // 选择数据库
            mysqli_select_db($link,$dbname);
            // 编码设置
            mysqli_set_charset($link,'utf8');
            // 创建连接
            $conn = new mysqli(HOST,$user,$pass,$dbname);
            // 检测连接
            if ($conn->connect_error) {
            die("<center><script>alert('数据库连接失败！');</script></center>");
            }
            setcookie("DB", $dbname, time()+7200);
            setcookie("CUSER", $user, time()+7200);
            setcookie("CPASS", $pass, time()+7200);
            $user=$pass=$dbname="";
            header('Location:http://localhost/SW-SmartWarehouse/login.php');
            }
            ?></center>
            
	</div>
        </div>
        <div class="bottom"></div>
        <div id="footer"><p>Copyright© 2019 版权所有 SW智能库存管理系统团队 V1.2.1 <a href="http://localhost/SW-SmartWarehouse/lianxi.php"><font color="#00FFFF">联系我们</font></a></p></div>
        <script>navList(12);</script>
    </body>
</html>
