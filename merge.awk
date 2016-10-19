#!/usr/bin/awk -f

BEGIN{
    FS="\\input{|}"
}
{
    regex="(%*)(.*)\\input{(.*)}";
    if(match($0,regex,a)){
        file = a[3];
        if(a[1]==""){
            match(file,".tex",b);
            if(RLENGTH<0){
                system("./merge.awk "file".tex");
            }
            else{
                system("./merge.awk "file);
            }
        }
    }
    else{
        print $0
    }
}
