package week10t4;

public class Main {
    public static void main(String[] args) {
        String s = "Hello, world!"; 
		// 创建一个字符串 s
        System.out.println(s.length()); 
		// 输出字符串 s 的长度
        System.out.println(s.charAt(0)); 
		// 输出字符串 s 的第一个字符
        String s1 = "Hello, Java!"; 
		// 创建另一个字符串 s1
        s.concat(s1); 
		// 尝试连接字符串 s 和 s1，但没有赋值给 s
        System.out.println(s); 
		// 输出字符串 s，仍然是 "Hello, world!"
        System.out.println(s.toLowerCase()); 
		// 输出字符串 s 的小写形式
        System.out.println(s.toUpperCase()); 
		// 输出字符串 s 的大写形式
        char[] chars = s.toCharArray(); 
		// 将字符串 s 转换为字符数组
        System.out.println(chars); 
		// 输出字符数组
        System.out.println(String.valueOf(12345)); 
		// 将整数 12345 转换为字符串并输出
        System.out.println("java is fun".matches("java.*")); 
		// 检查字符串是否匹配正则表达式并输出结果
        System.out.println(s.replace('W','A')); 
		// 将字符串 s 中的字符 'W' 替换为 'A' 并输出
        String s2 = "AAA#BBB#CCC"; 
		// 创建一个字符串 s2
        String[] token = s2.split("#"); 
		// 将字符串 s2 按照 "#" 分割成字符串数组
        for(int i = 0 ; i < token.length; i++) {
            System.out.print(token[i] + " "); 
			// 输出分割后的每个字符串
        }
    }
}