function switchColor(_class)
{
    if (_class.className == "off")
    {
        // console.log(_class);
        // console.log(this);
        // console.log(typeof _class);
        _class.className = "on";
        // let class_id = _class.id;
        // console.log("_class inner HTML =",_class.getElementsByTagName("p"));
        // console.log(_class.innerHTML);
        _class.innerHTML = "<p> ON <p>";
        // console.log(_class.p);
        // document.getElementById(class_id).firstChild.innerText = "ON";
    }
    else if (_class.className == "on")
    {
        _class.className = "off";
        _class.innerHTML = "<p> OFF </p>";
    }
    var array_class1 = document.getElementById("row1").children;
    let bulb = document.getElementById("big-tube");
    for (i = 0; i<array_class1.length; i++)
    {
        if (array_class1[i].className == "off")
        {
            // console.log("bulb =",bulb);
            // console.log("before: bulb.className =",bulb.className)
            bulb.className = "tubelight-off";
            break;
            // console.log("after: bulb.className =",bulb.className)
            
        }
        bulb.className = "tubelight-on";

    }
}

function toggleColor(_class)
{
    // console.log("So far so good");
    var array_class2 = document.getElementById("row2").children;

    console.log("array_class2 =",array_class2);
    console.log("_class =",_class);
    if (_class.className == "off")
    {    
        for (i = 0; i<array_class2.length; i++)
        {
            array_class2[i].className = "off";
            // console.log(array_class2[i].className)

            let small_bulb = array_class2[i].id;
            // console.log("small_bulb = ",small_bulb);
            small_bulb+="tube";
            // console.log("small_bulb2 = ",small_bulb);
            let small_bulb2 = document.getElementById(small_bulb);
            small_bulb2.className = "small-tubelight-off";
            array_class2[i].innerHTML = "<p> OFF </p>"
        }
        let small_bulb = _class.id;
        small_bulb+="tube";
        _class.className = "on";
        let small_bulb2 = document.getElementById(small_bulb);
        small_bulb2.className = "small-tubelight-on";
        _class.innerHTML = "<p> ON </p>"
    }
    else if (_class.className == "on")
    {
        _class.className = "off";
        let small_bulb = _class.id;
        small_bulb+="tube";
        let small_bulb2 = document.getElementById(small_bulb);
        small_bulb2.className = "small-tubelight-off";
        _class.innerHTML = "<p> OFF </p>";
    }
}