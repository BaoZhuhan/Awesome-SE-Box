function calStanddeviation() {
    var inputVal = document.getElementById("input").value;

    var num = inputVal.split(' ').map(Number);

    var maxDecimalLength = Math.max(...num.map(n => ((n.toString().split('.')[1] || '').length)));

    var avg = num.reduce((a, b) => a + b, 0) / num.length;

    var up = 0;

    for (var i = 0; i < num.length; i++) {
        up += (num[i] - avg) * (num[i] - avg);
    }

    var ans = up / (num.length - 1);

    ans = Math.sqrt(ans);

    ans = ans.toFixed(maxDecimalLength);

    alert(ans);
}