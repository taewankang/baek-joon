var arr=new Array();
var counting=0;
function getArea(name, a, b, c, d){
    logging(name);
    if(name=='circle'){
        if(two_ar_exception(a, b, c))   //원의 넓이
            console.log(circle_area(a, b));            
    }
    else if(name=='parallelogram'){
        if(two_ar_exception(a, b, c))       //평행사변형의 넓이
            console.log(parallelogram_area(a, b));
    }
    else if(name=='trapezoid'){         //사다리꼴의 넓이
        if(three_ar_exception(a, b, c, d))
            console.log(trapezoid_area(a, b, c));
    }
    else{
        console.log('잘못된 입력입니다.');
    }
}

function printExecutionSequence(){
    console.log('계산수행순서');
    for(let i=0; i<counting; i++)
        console.log(arr[i]);
}

function logging(name){
    if(name=='circle' || name=='parallelogram' || name=='trapezoid'){
        arr[counting]=name;
        counting++;
    }
    return arr;
}

function getAreaAvg(name, a, b, c){
    if(name=='circle'){
        if(two_ar_exception(a, b, c))
            console.log(circle_avg_area(a, b));
    }
    else{
        console.log('잘못된 입력입니다.');
    }
}

function parallelogram_area(width, height){
    return width*height;
}

function circle_avg_area(start, end){
    let result=0;
    for(let i=start; i<=end; i++){
        result+=circle_area(i, 3.14);
    }
    if(start > end){
        let temp=start;
        start=end;
        end=temp;
    }
    result /= (end - start + 1); 
    return result;
}

function circle_area(radius, pi){
    return radius * radius * pi;
}

function trapezoid_area(up, down, height){
    return ((up + down) * height) / 2;
}

function two_ar_exception(a, b ,c){
    if(a== undefined || b== undefined){
        console.log('에러에요! 인자가 부족합니다.');
        return false;
    }
    else if(c != undefined){
        console.log('에러에요! 인자가 많습니다.');
        return false;
    }
    return true;
}

function three_ar_exception(a, b, c, d){
    if(a==undefined || c==undefined){
        console.log('에러에요! 인자가 부족합니다.');
        return false;
    }
    else if(d != undefined){
        console.log('에러에요! 인자가 많습니다.');
        return false;
    }
    return true;
}

getArea('circle', 10, 3.14);
getArea('parallelogram', 10, 15);
getArea('trapezoid', 10, 15, 12);
getArea('trapezoid', 10);
getAreaAvg('circle', 5, 11);
printExecutionSequence();