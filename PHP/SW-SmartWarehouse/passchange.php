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
            <?php
            // 定义变量并默认设置为空值
            $oldpassErr = $passErr = $testpassErr ="";
            $oldpass = $pass = $testpass ="";

        if ($_SERVER["REQUEST_METHOD"] == "POST")
        {
            
            if (empty($_POST["oldpass"]))
            {
            $oldpassErr = " 请输入原密码";
            }
            else
            {
            $oldpass = test_input($_POST["oldpass"]);
            }
    
            if (empty($_POST["pass"]))
            {
            $passErr = " 请输入新密码";
            }
            else
            {
            $pass = test_input($_POST["pass"]);
            }
            
            if (empty($_POST["testpass"]))
            {
            $testpassErr = " 请再次输入新密码";
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
            <br>
            <br>
            <center><h2><?php echo '尊敬的'.$username.'，请输入：';?></h2></center>
            <br>
            <center>
            <form name="passchange" method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
            <table width="509" border="0">
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>原&nbsp;&nbsp密&nbsp;&nbsp码：    </h3></td>
            <td width="104" height="60"><input type="text"name="oldpass" size="20" value="<?php echo $oldpass;?>"/><span class="error"><?php echo $oldpassErr;?></span></td>
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
                <td height="60" colspan="3"><input type="submit" name="sumbit" value="确认修改" style="height:45px;width:85px;"/></td>
            </tr>
            </table>
            </form>
            </center><br>
            <center><h3><a href="http://localhost/SW-SmartWarehouse/index.php">返回</a></h3></center>
            <center><?php
            if($_COOKIE['DB']=="")
            {
            echo "<br>";
            ?>
            <span class="error"><center><h2><a href="http://localhost/SW-SmartWarehouse/complogin.php"><span class="error">您还没有登录数据库，请先返回登录数据库！</span></a></h2></center></span>
            <?php
            }
            if($oldpass==""||$pass==""||$testpass=="")
            {
            echo "<br>";
            echo '<center>请输入以上信息</center>';
            }
            else
            {   
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
            // 读取数据
            $user=$_COOKIE['SID'];
            $query="SELECT password FROM staffmember WHERE staffID='$user'";
            $result = $conn->query($query);
            if (!$result) {
            die("<center><script>alert('数据读取失败！');</script></center>");
            }
            $rows=$result->num_rows;
            
            //检验原密码是否正确
            if($oldpass==$result->fetch_assoc()['password']){
                //检验两次新密码是否输入一致
                if($pass==$testpass){
                //尝试修改密码
                $query="UPDATE staffmember SET password='$pass' WHERE staffID='$user'";
                $result = $conn->query($query);
                //修改失败提示
                if (!$result) {die("<center><script>alert('数据读取失败！');</script></center>");}
                //修改成功提示
                ?><center><script>alert('修改成功！');</script></center><?php
                }
                //两次密码输入不一致
                else{
                    echo '<h2><center><span class="error">请确认新密码！</span></center><h2>';
                }
            }
            //原密码错误
            else{
                echo '<h2><center><span class="error">原密码错误！</span></center><h2>';
            }
            //重置变量
            $oldpass = $pass = $testpass = $user = "";
            $query="SELECT password FROM staffmember WHERE staffID='$user'";
            $result = $conn->query($query);
            $rows=$result->num_rows;
            // 释放内存
            mysqli_free_result($result);
            mysqli_close($conn);
            }
            ?></center>
            
	</div>
        </div>
        <div class="bottom"></div>
        <div id="footer"><p>Copyright© 2019 版权所有 SW智能库存管理系统团队 V1.2.1 <a href="http://localhost/SW-SmartWarehouse/lianxi.php"><font color="#00FFFF">联系我们</font></a></p></div>
        <script>navList(12);</script>
    </body>
</html>
