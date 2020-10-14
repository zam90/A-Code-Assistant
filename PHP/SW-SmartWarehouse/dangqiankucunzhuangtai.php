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
	<div class="left_menu">
				<ul id="nav_dot">
        <li>
          <h4 class="M7"><span></span>库存状态</h4>
          <div class="list-item none">
            <a href='http://localhost/SW-SmartWarehouse/dangqiankucunzhuangtai.php'>当前库存状态</a>
          </div>
        </li>
        <li>
          <h4 class="M9"><span></span>出入库信息</h4>
          <div class="list-item none">
            <a href='http://localhost/SW-SmartWarehouse/information-today.php'>今日出入库信息</a>
            <a href='http://localhost/SW-SmartWarehouse/information-week.php'>本周出入库信息</a>
            <a href='http://localhost/SW-SmartWarehouse/information-month.php'>本月出入库信息</a>
            <a href='http://localhost/SW-SmartWarehouse/information-3monthes.php'>当季出入库信息</a>
            <a href='http://localhost/SW-SmartWarehouse/information-halfyear.php'>半年出入库信息</a>
            <a href='http://localhost/SW-SmartWarehouse/information-year.php'>一年出入库信息</a>
            <a href='http://localhost/SW-SmartWarehouse/information-all.php'>全部出入库信息</a>
          </div>
        </li>
        <li>
          <h4  class="M2"><span></span>数据统计</h4>
          <div class="list-item none">
            <a href='http://localhost/SW-SmartWarehouse/data-today.php'>今日数据统计</a>
            <a href='http://localhost/SW-SmartWarehouse/data-week.php'>本周数据统计</a>
            <a href='http://localhost/SW-SmartWarehouse/data-month.php'>本月数据统计</a>
            <a href='http://localhost/SW-SmartWarehouse/data-3monthes.php'>当季数据统计</a>
            <a href='http://localhost/SW-SmartWarehouse/data-halfyear.php'>半年数据统计</a>
            <a href='http://localhost/SW-SmartWarehouse/data-year.php'>一年数据统计</a>
            <a href='http://localhost/SW-SmartWarehouse/data-all.php'>全部数据统计</a>
          </div>
        </li>
        <li>
          <h4  class="M6"><span></span>数据修改</h4>
          <div class="list-item none">
            <a href=''>入库</a>
            <a href=''>出库</a>
          </div>
        </li>
        <li>
          <h4   class="M10"><span></span>人员管理</h4>
          <div class="list-item none">
            <a href='http://localhost/SW-SmartWarehouse/membereditor.php'>人员编辑</a>
            <a href='http://localhost/SW-SmartWarehouse/membermanagement.php'>人员权限管理</a>
          </div>
        </li>
        <li>
          <h4 class="M1"><span></span>通知公告</h4>
          <div class="list-item none">
            <a href='http://localhost/SW-SmartWarehouse/xitongtongzhi.php'>系统通知</a>
            <a href='http://localhost/SW-SmartWarehouse/gengxinrizhi.php'>更新日志</a>
          </div>
        </li>
        </ul>
        </div>
            <div class="m-right">
            <div class="right-nav">
            <ul>
            <li><img src="images/home.png"></li>
                    <li style="margin-left:25px;">您当前的位置：</li>
                    <li>库存状态</li>
                    <li>></li>
                    <li><a href="http://localhost/SW-SmartWarehouse/dangqiankucunzhuangtai.php">当前库存状态</a></li>
            </ul>
	</div>
	<div class="main">
            <br>
            <center><h3>
            <?php
            function ShowTable($table_name){
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
            $sql = "SELECT productname,productID,specification,productdate,productarea,manufacturer,inarea,outarea,indate,outdate,instaff,outstaff,quantity,conditions FROM product";
            $res = $conn->query($sql);
            $rows=mysqli_affected_rows($conn);//获取行数
            $colums=mysqli_num_fields($res);//获取列数
            echo "<h2>当前库存状态</h2><br/>";
        
            echo "<table><tr>";
            //循环打印表头
            for($i=0; $i < $colums; $i++){
            if($i==0){$excel='商品名称';}if($i==1){$excel='商品编号';}if($i==2){$excel='规格';}if($i==3){$excel='生产日期';}
            if($i==4){$excel='生产地';}if($i==5){$excel='生产厂家';}if($i==6){$excel='入库来源';}if($i==7){$excel='出库流向';}
            if($i==8){$excel='入库时间';}if($i==9){$excel='出库时间';}if($i==10){$excel='入库经手人';}if($i==11){$excel='出库经手人';}
            if($i==12){$excel='数量';}if($i==13){$excel='状态';}
            echo "<th><center>$excel</center></th>";
            }
            echo "</tr>";
            //循环打印数据
            while($row=mysqli_fetch_row($res)){
            echo "<tr>";
            for($i=0; $i<$colums; $i++){
                echo "<td><center>$row[$i]</center></td>";
            }
            echo "</tr>";
        }
        echo "</table>";
    }
    ShowTable("test1");
            ?></h3></center>
	</div>
	</div>
        </div>
        <div class="bottom"></div>
        <div id="footer"><p>Copyright 2019 版权所有 SW智能库存管理系统团队 V1.2.1 <a href="http://localhost/SW-SmartWarehouse/lianxi.php"><font color="#00FFFF">联系我们</font></a></p></div>
        <script>navList(12);</script>
        
        
    </body>
</html>