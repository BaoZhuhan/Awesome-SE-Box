/*获取页面上按钮元素。*/
var button = document.querySelector('button');
/*为按钮添加事件监听器。当单击按钮时，创建一个图像元素并添加到section区域的底部。*/
button.addEventListener('click', function () {
    var img = document.querySelector('img');
    var section = document.querySelector('section');
    if (img == null) {
        img = document.createElement('img');
        img.src = 'images\/about-bookstore.jpg';
        section.appendChild(img);
    }
}, false)
