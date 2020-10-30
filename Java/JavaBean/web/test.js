function Test(){
    var sid=document.inf.sid.value;
    var sidrule=/^[0-9]*$/;
    var pwd1=document.inf.password1.value;
    var pwd2=document.inf.password2.value;
    var sname=document.inf.sname.value;
    var accept=document.inf.read.checked;

    if(sid.length<=0){
        alert("学号不能为空");
    }
    else if(!sidrule.test(sid)){
        alert("学号应为纯数字");
    }
    else if(pwd1.length<3){
        alert("密码长度不能小于3位");
    }
    else if(pwd1!=pwd2){
        alert("两次密码不一致");
    }
    else if(sname.length<=0){
        alert("姓名不能为空");
    }
    else if(accept!=true){
        alert("同意接受用户使用协议");
    }
    else{
        document.inf.submit();
    }
}