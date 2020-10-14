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
                    $link = mysqli_connect(HOST,$_COOKIE['CUSER'],$_COOKIE['CPASS']) or die("<center><script>alert('连接数据库失败！');</script></center>");
                    // 选择数据库
                    mysqli_select_db($link,$_COOKIE['DB']);
                    // 编码设置
                    mysqli_set_charset($link,'utf8');
                    // 创建连接
                    $conn = new mysqli(HOST,$_COOKIE['CUSER'],$_COOKIE['CPASS'],$_COOKIE['DB']);
                    // 检测连接
                    if ($conn->connect_error) {
                    die("<center><script>alert('连接数据库失败！');</script></center>");
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
            //连接mysql
                    $link = mysqli_connect(HOST,$_COOKIE['CUSER'],$_COOKIE['CPASS']) or die("<center><script>alert('连接数据库失败！');</script></center>");
                    // 选择数据库
                    mysqli_select_db($link,$_COOKIE['DB']);
                    // 编码设置
                    mysqli_set_charset($link,'utf8');
                    // 创建连接
                    $conn = new mysqli(HOST,$_COOKIE['CUSER'],$_COOKIE['CPASS'],$_COOKIE['DB']);
                    // 检测连接
                    if ($conn->connect_error) {
                    die("<center><script>alert('连接数据库失败！');</script></center>");
                    } 
                    // 获取用户信息
                    $useri=$_COOKIE['SID'];
                    $query="SELECT staffname,staffID,duty,rank FROM staffmember WHERE staffID='$useri'";
                    $result = $conn->query($query);
                    if (!$result) {
                    die("<center><script>alert('数据读取失败！');</script></center>");
                    }
                    $rows=$result->num_rows;
                    for($j=0;$j<$rows;++$j)
                    {
                        $result->data_seek($j);
                        $row=$result->fetch_array(MYSQLI_ASSOC);
                        $staffname=$row['staffname'];
                        $staffID=$row['staffID'];
                        $duty=$row['duty'];
                        $rank=$row['rank'];
                    }
                    
            // 定义变量并默认设置为空值
            $userErr = $nameErr = $dutErr = $ranErr ="";
            $user=$staffID;$name=$staffname;$dut=$duty;$ran=$rank;

        if ($_SERVER["REQUEST_METHOD"] == "POST")
        {
            if (empty($_POST["user"]))
            {
            $userErr = " 请输入员工编号";
            }
            if (empty($_POST["name"]))
            {
            $nameErr = " 请输入员工姓名";
            }
            else
            {
            $name = test_input($_POST["name"]);
            }
            if (empty($_POST["dut"]))
            {
            $dutErr = " 请输入员工职务";
            }
            else
            {
            $dut = test_input($_POST["dut"]);
            }
            if (empty($_POST["ran"]))
            {
            $ranErr = " 请输入员工级别";
            }
            else
            {
            $ran = test_input($_POST["ran"]);
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
            <center><h2>员工信息</h2></center>
            <br>
            <center>
            <form name="signup" method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
            <table width="509" border="0">
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>员工编号：    </h3></td>
            <td width="104" height="60"><input type="text" name="user" size="20" value="<?php echo $user;?>"/><span class="error"><?php echo $userErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>员工姓名：    </h3></td>
            <td width="104" height="60"><input type="text"name="name" size="20" value="<?php echo $name;?>"/><span class="error"><?php echo $nameErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>员工职务：    </h3></td>
            <td width="104" height="60"><input type="text"name="dut" size="20" value="<?php echo $dut;?>"/><span class="error"><?php echo $dutErr;?></span></td>
            </tr>
            <tr bgcolor="#FFFFFF">
            <td width="103" height="60" align="right"><h3>员工级别：    </h3></td>
            <td width="104" height="60"><input type="text"name="ran" size="20" value="<?php echo $ran;?>"/><span class="error"><?php echo $ranErr;?></span></td>
            </tr>
            <tr align="center" bgcolor="#FFFFFF">
                <td height="60" colspan="3"><input type="submit" name="sumbit" value="确认修改" style="height:45px;width:85px;"/></td>
            </tr>
            </table>
            </form>
                <center><h3>●员工编号不可修改！</h3></center>
                <?php
                if($user == ''||$name == ''||$dut == ''|| $ran == '')
                {
                    echo "<br>";
                    echo '<center>请输入以上信息</center>';
                }
                else{
                    if($staffname!=$name)
                    {$query="UPDATE staffmember SET staffname='$name' WHERE staffID='$user'";
                    $result = $conn->query($query);
                    //修改失败提示
                    if (!$result) {die("<center><script>alert('数据读取失败！');</script></center>");}
                    //修改成功提示
                    ?><center><script>alert('修改成功！');</script></center><?php
                    }
                    if($dut!=$duty)
                    {$query="UPDATE staffmember SET duty='$dut' WHERE staffID='$user'";
                    $result = $conn->query($query);
                    //修改失败提示
                    if (!$result) {die("<center><script>alert('数据读取失败！');</script></center>");}
                    //修改成功提示
                    ?><center><script>alert('修改成功！');</script></center><?php
                    }
                    if($ran!=$rank)
                    {$query="UPDATE staffmember SET rank='$ran' WHERE staffID='$user'";
                    $result = $conn->query($query);
                    //修改失败提示
                    if (!$result) {die("<center><script>alert('数据读取失败！');</script></center>");}
                    //修改成功提示
                    ?><center><script>alert('修改成功！');</script></center><?php
                    }
                    
                }
                ?>
            </center><br>
            <center><h3><a href="http://localhost/SW-SmartWarehouse/index.php">返回</a></h3></center>
            <center>
	</div>
        </div>
        <div class="bottom"></div>
        <div id="footer"><p>Copyright© 2019 版权所有 SW智能库存管理系统团队 V1.2.1 <a href="http://localhost/SW-SmartWarehouse/lianxi.php"><font color="#00FFFF">联系我们</font></a></p></div>
        <script>navList(12);</script>
    </body>
</html>
