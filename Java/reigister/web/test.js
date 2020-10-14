function Test(){
    var name=document.inf.Username.value;
    var namerule=/[a-zA-Z]\w*/;
    var pwd1=document.inf.Userpassword.value;
    var pwd2=document.inf.Userpassword1.value;
    var truename=document.inf.UserTrueName.value;
    var ID=document.inf.UserID.value;
    var email=document.inf.Email.value;
    var emailrule=/\w+([-+.']\w+)*@\w+([-.]\w+)*.\w+([-.]\w+)*/;
    var accept=document.inf.read.checked;

    if(name.length<=0){
        alert("用户名不能为空");
    }
    else if(!namerule.test(name)){
        alert("用户名格式不正确");
    }
    else if(pwd1.length<3){
        alert("密码长度不能小于3位");
    }
    else if(pwd1!=pwd2){
        alert("两次密码不一致");
    }
    else if(truename.length<=0){
        alert("性名不能为空");
    }
    //身份证号码为18位
    else if(ID.length!==18){
        alert("身份证格式错误");
    }
    else if(email.length>0 && !emailrule.test(email)){
        alert("邮箱格式不正确");
    }
    else if(accept!=true){
        alert("同意接受用户使用协议");
    }
    else{
        document.inf.submit();
    }
}