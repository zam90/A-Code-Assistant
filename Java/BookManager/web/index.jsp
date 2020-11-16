<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="DAO.BookDAO" %>
<%@ page import="VO.Book" %>
<%@ page import="java.util.List" %>


<!DOCTYPE html>
<!-- 网页使用的语言 -->
<html lang="zh-CN">
<head>
    <title>图书借阅</title>

    <!-- 1. 导入CSS的全局样式 -->
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <!-- 2. jQuery导入，建议使用1.9以上的版本 -->
    <script src="js/jquery-2.1.0.min.js"></script>
    <!-- 3. 导入bootstrap的js文件 -->
    <script src="js/bootstrap.min.js"></script>
    <style type="text/css">
        td, th {
            text-align: center;
        }
    </style>

    <script>
        function bookout(bookId) {
            if(confirm("您确定借阅这本书么？"))
                location.href="bookOutJDBC.jsp?bookId="+bookId;
        }
    </script>

</head>
<body>
<%
    BookDAO DAO = new BookDAO();
    List<Book> books = DAO.bookAll();
    request.setAttribute("books",books);
%>
<div class="container">
    <h3 style="text-align: center">图书列表</h3>
    <div style="float: right;margin:5px">
        <a class="btn btn-primary" href="stuInf.jsp" id="stuInf">个人信息</a>
    </div>
    <div style="float: right;margin:5px">
        <a class="btn btn-primary" href=" " id="bookRecord">借阅记录</a>
    </div>

    <div  style="float: left;margin:5px" action=" " method="post">
        <form class="form-inline">
            <div class="form-group">
                <label for="exampleInputEmail2">名称</label>
                <input type="text"  name="bookName" value=" " class="form-control" id="exampleInputEmail2" >
            </div>
            <div class="form-group">
                <label for="exampleInputName3">分类</label>
                <input type="text" name="bookClassify"value=" " class="form-control" id="exampleInputName3" >
            </div>
            <button type="submit" class="btn btn-default">查询</button>
        </form>
    </div>
    <form  id="form" action=" " method="post">
        <table border="1" class="table table-bordered table-hover">
            <tr class="success">
                <th>编号</th>
                <th>书名</th>
                <th>类别</th>
                <th>数量</th>
                <th>操作</th>
            </tr>
            <%
                for (Book book : books) {
            %>
            <tr>
                <td><%=book.getBookId()%>
                </td>
                <td><%=book.getBookName()%>
                </td>
                <td><%=book.getBookClassify()%>
                </td>
                <td><%=book.getBookCount()%>
                </td>
                <td><a class="btn btn-primary" href="javascript:bookout(<%=book.getBookId()%>);">借阅</a></td>
            </tr>
            <%
                }
            %>
        </table>
    </form>

</div>
</body>
</html>
