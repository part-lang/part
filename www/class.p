class Hello
    public say = 'Null'
    def talk(var text)
    this->say = var.text
    end
end

var hello = new Hello()
print var.hello->talk("Hello World")
print var.hello->say