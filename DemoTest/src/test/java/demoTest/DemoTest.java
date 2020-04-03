package demoTest;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.assertThat;


public class DemoTest {

    WebDriver driver;

    @Before
    public void setUp() throws Exception {
        System.setProperty("webdriver.chrome.driver", "E:/driver/chromedriver.exe");
        driver = new ChromeDriver();
    }

    @Test
    public void test1() throws Exception {
        driver.get("http://dl.webxgame.com/");
        System.out.println(driver.getTitle());
        assertThat("斗罗大陆|斗罗大陆网页游戏|斗罗大陆2绝世唐门|斗罗大陆txt|e侠网", is(driver.getTitle()));

    }

    @Test
    public void test2() throws Exception {
        driver.get("http://dl.webxgame.com/");
        String text = driver.findElement(By.partialLinkText("忘记密码？")).getText();
        assertThat("忘记密码？", is(text));
    }

    @Test
    public void test3() throws Exception {
        driver.get("http://dl.webxgame.com/");
        driver.findElement(By.id("username")).sendKeys("515151");
        driver.findElement(By.id("password")).sendKeys("515151");
        driver.findElement(By.name("onsubmit")).click();
        String now = driver.getCurrentUrl();
        assertThat("http://www.webxgame.com/interface/home/login.php", is(now));
    }

    @Test
    public void test4() throws Exception {
        driver.get("http://dl.webxgame.com/");
        driver.findElement(By.id("username")).sendKeys("515151");
        driver.findElement(By.id("password")).sendKeys("51515151");
        driver.findElement(By.name("onsubmit")).click();
        driver.switchTo().alert().accept(); //点击确认
        String now = driver.getCurrentUrl();
        assertThat("http://www.webxgame.com/interface/home/login.php", is(now));
    }

    @After
    public void tearDown() throws Exception {
        Thread.sleep(5000);
        driver.quit();
    }

}