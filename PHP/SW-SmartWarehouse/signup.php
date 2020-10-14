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
			<li><a href="http://localhost/SW-SmartWarehouse/signup.php"><h3>注册</h3></a></li>
		</ul>
	</div>
        </div>
        <div id="content">
        <div class="main">
            <?php require "Host-set.php";//导入配置文件 ?>
            <?php
            // 定义变量并默认设置为空值
            $userErr = $passErr = $testpassErr = $staffnameErr = $dutyErr = $rankErr = $permissionErr ="";
            $user = $pass = $testpass = $staffname = $duty = $rank = $permission ="";

        if ($_SERVER["REQUEST_METHOD"] == "POST")
        {
            if (empty($_POST["user"]))
            {
            $userErr = " 请输入员工编号";
            }
            else
            {
            $user = test_input($_POST["user"]);
            }
            if (empty($_POST["staffname"]))
            {
            $staffnameErr = " 请输入员工姓名";
            }
            else
            {
            $staffname = test_input($_POST["staffname"]);
            }
            if (empty($_POST["duty"]))
            {
            $dutyErr = " 请输入员工职务";
            }
            else
            {
            $duty = test_input($_POST["duty"]);
            }
            if (empty($_POST["rank"]))
            {
            $rankErr = " 请输入员工级别";
            }
            else
            {
            $rank = test_input($_POST["rank"]);
            }
            if (empty($_POST["permission"]))
            {
            $permissionErr = " 请输入员工权限";
            }
            else
            {
            $permission = test_input($_POST["permission"]);
            }
            if (empty($_POST["pass"]))
            {
            $passErr = " 请输入密码";
            }
            else
            {
            $pass = test_input($_POST["pass"]);
            }
            if (empty($_POST["testpass"]))
            {
            $testpassErr = " 请再次输入密码";
            }
            else
            {
            $testpass = test_input($_POST["testpass"]);
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
            <center><h2>欢迎注册SW智能库存管理系统! 请输入：</h2></center>
            <br>
            <center>
            <form name="signup" method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
            <table width="509" border="0">
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>员工编号：    </h3></td>
            <td width="104" height="60"><input type="text"name="user" size="20" value="<?php echo $user;?>"/><span class="error"><?php echo $userErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>员工姓名：    </h3></td>
            <td width="104" height="60"><input type="text"name="staffname" size="20" value="<?php echo $staffname;?>"/><span class="error"><?php echo $staffnameErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>员工职务：    </h3></td>
            <td width="104" height="60"><input type="text"name="duty" size="20" value="<?php echo $duty;?>"/><span class="error"><?php echo $dutyErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>员工级别：    </h3></td>
            <td width="104" height="60"><input type="text"name="rank" size="20" value="<?php echo $rank;?>"/><span class="error"><?php echo $rankErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>员工权限：    </h3></td>
            <td width="104" height="60"><input type="number"name="permission" size="20" value="<?php echo $permission;?>"/><span class="error"><?php echo $permissionErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>密&nbsp;&nbsp码：    </h3></td>
            <td width="104" height="60"><input type="text" name="pass" size="20" value="<?php echo $pass;?>"/><span class="error"><?php echo $passErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>确&nbsp;&nbsp认&nbsp;&nbsp密&nbsp;&nbsp码：    </h3></td>
            <td width="104" height="60"><input type="text" name="testpass" size="20" value="<?php echo $testpass;?>"/><span class="error"><?php echo $testpassErr;?></span></td>
            </tr>
            <tr align="center" bgcolor="#FFFFFF">
                <td height="60" colspan="3"><input type="submit" name="sumbit" value="注册" style="height:45px;width:85px;"/></td>
            </tr>
            </table>
            </form>
            </center><br>
            <center><h3><a href="http://localhost/SW-SmartWarehouse/login.php">返回登录</a></h3></center>
            <center><h3><a href="http://localhost/SW-SmartWarehouse/losepassword.php">注册遇到问题？</a></h3></center>
            <center><?php
            if($_COOKIE['DB']=="")
            {
            echo "<br>";
            ?>
            <span class="error"><center><h2><a href="http://localhost/SW-SmartWarehouse/complogin.php"><span class="error">您还没有登录数据库，请先返回登录数据库！</span></a></h2></center></span>
            <?php
            }
            if($pass==""||$user==""||$testpass==""||$staffname==""||$duty==""||$rank==""||$permission=="")
            {
            echo "<br>";
            echo '<center>请输入以上信息</center>';
            }
            else
            {
                if($pass==$testpass)
                {
                // 创建连接
                $link = mysqli_connect(HOST,$_COOKIE['CUSER'],$_COOKIE['CPASS']) or die("提示：数据库连接失败！");
                // 选择数据库
                mysqli_select_db($link,$_COOKIE['DB']);
                // 编码设置
                mysqli_set_charset($link,'utf8');
                // 创建连接
                $conn = new mysqli(HOST,$_COOKIE['CUSER'],$_COOKIE['CPASS'],$_COOKIE['DB']);
                // 检测连接
                if ($conn->connect_error) {
                die("连接失败: " . $conn->connect_error);
                } 
                
                //尝试插入数据
                $sql = "INSERT INTO staffmember (staffname,staffID,password,duty,rank,permission)
                VALUES ('".$staffname."', '".$user."', '".$pass."', '".$duty."', '".$rank."', $permission)";
                //注册成功
                if ($conn->query($sql) === TRUE) {
                ?><h1><font color= '#FF0000'><a href="http://localhost/SW-SmartWarehouse/login.php">注册成功，请返回登录！</a></font></h1><?php
                } 
                else {
                echo "数据库错误: " . $sql . "<br>" . $conn->error;
                }
                }
                //密码输入不一致
                else
                {
                    echo '<br>';
                    echo '<span class="error"><h2>两次密码输入不一致，请重新输入</h2></span>';
                }
            }
            
            ?></center>
	</div>
        </div>
        <div class="bottom"></div>
        <div id="footer"><p>Copyright© 2019 版权所有 SW智能库存管理系统团队 V1.2.1 <a href="http://localhost/SW-SmartWarehouse/lianxi.php"><font color="#00FFFF">联系我们</font></a></p></div>
        <script>navList(12);</script>
    </body>
</html>
