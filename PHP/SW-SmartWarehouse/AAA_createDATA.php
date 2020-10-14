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
    <style>.error {color: #FF0000;}</style>
</head>
<body>
    <?php require "Host-set.php";//导入配置文件 ?>
    <?php
// 定义变量并默认设置为空值
/*$hostErr = $userErr = $passErr = $dbnameErr = "";
$host = $user = $pass = $dbname = "";

if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    if (empty($_POST["host"]))
    {
        $hostErr = "host是必需的";
    }
    else
    {
        $host = test_input($_POST["host"]);
    }
    
    if (empty($_POST["user"]))
    {
      $userErr = "user是必需的";
    }
    else
    {
        $user = test_input($_POST["user"]);
    }
    
    if (empty($_POST["pass"]))
    {
        $passErr = "pass是必需的";
    }
    else
    {
        $pass = test_input($_POST["pass"]);
    }
    
    if (empty($_POST["dbname"]))
    {
        $dbnameErr = "dbname是必需的";
    }
    else
    {
        $dbname = test_input($_POST["dbname"]);
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

<center><h2>数据库新建表单</h2><center/>
<p><span class="error">*为必需字段，请务必填写并保证正确性。</span></p>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>"> <center>
   host: <input type="text" name="host" value="<?php echo $host;?>">
   <span class="error">* <?php echo $hostErr;?></span>
   <br><br>
   user: <input type="text" name="user" value="<?php echo $user;?>">
   <span class="error">* <?php echo $userErr;?></span>
   <br><br>
   pass: <input type="text" name="pass" value="<?php echo $pass;?>">
   <span class="error"><?php echo $passErr;?></span>
   <br><br>
   dbname: <input type="text" name="dbname" value="<?php echo $dbname;?>">
   <span class="error"><?php echo $dbnameErr;?></span>
   <br><br>
   <input type="submit" name="submit" value="确认创建"> <center/>
</form>

<?php
if($host==""||$user==""||$pass==""||$dbname=="")
{
    echo "<br>";
    echo '请输入以上数据';
}
else
{
echo "<h2>操作结果:</h2>";
*/
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
            //$sql = "INSERT INTO staffmember (staffname,staffID,duty,rank,permission)
            //VALUES ('zjy', '001', 'boss', 'boss', '1')";
            
            $number=45;$ID='orju';
            $query="SELECT quantity FROM product WHERE productID='$ID'";
            $result = $conn->query($query);
            if (!$result) {
            die("<center><script>alert('数据读取失败！');</script></center>");
            }
            $rows=$result->num_rows;
            if($result->fetch_assoc()['quantity']>0){
                $exam='true';
                $quantity=intval($result->fetch_assoc()['quantity']);
                $total=$quantity+$number;
            }else{
                $exam='false';
            }
            
            if($exam == 'true')
            {
                //尝试修改数量
                $query="UPDATE product SET quantity=$total WHERE productID='$ID'";
                $result = $conn->query($query);
                //修改失败提示
                if (!$result) {die("<center><script>alert('数据读取失败！');</script></center>");}
                //修改成功提示
                ?><center><script>alert('入库成功！');</script></center><?php
            }
            else
            {
                $sql = "INSERT INTO product (productname,productID,specification,productdate,productarea,manufacturer,inarea,outarea,indate,outdate,instaff,outstaff,quantity,conditions)
            VALUES ('汇源橙汁', 'orju', '瓶', '2019-04-18 19:39:16', '中国', '汇源公司', '超市', '', now(), NULL, 'NPC1', '',55, '存库')";
            
            if ($conn->query($sql) === TRUE) {
            echo "新记录插入成功";
            } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
            }
            }
            
//}
?>

</body>
</html>