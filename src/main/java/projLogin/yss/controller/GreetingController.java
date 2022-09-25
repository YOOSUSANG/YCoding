package projLogin.yss.controller;


import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;



@Controller
public class GreetingController{

    @GetMapping("/greeting")
    public String greeting (String name, Model model){
        Hello hello = new Hello();
        hello.setName("유수상");
        model.addAttribute("name",hello);
        return "greeting";
    }
    static class Hello{
        private String name;
        public String getName() {
            return name;
        }
        public void setName(String name) {
            this.name = name;
        }
    }
}
