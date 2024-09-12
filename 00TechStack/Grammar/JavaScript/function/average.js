function get_precision(num) {
    var valueString = num.toString();
    if (valueString.indexOf('.') !== -1) {
        return valueString.split('.')[1].length;
    } else { return 0; }
}

/*func:get_average() can get a string array and return its average*/
function get_average(nums) {
    var sum = 0;
    var res = 0;
    var precision = 30; /*For most experiment , 30 is a unbelievable precision*/
    for (var i = 0; i < nums.length; i++) {
        sum += nums[i];
        precision = (get_precision(nums[i]) < precision)?get_precision(nums[i]) : precision;
    }
    res = sum / nums.length;
    return Number(res.toFixed(precision));
}

function run(order) {
    if (order == 'get_average') {
        var userInput = ['1.1','1.2','3.33','1.10','1.33'];
        var res = get_average(userInput);
        console.log(res);
    }
}