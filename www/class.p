class Hello
    public say = 'Null'
    def talk(@text)
    this->say = @text
    end
end

@hello = new Hello()
print @hello->talk("Hello World")
print @hello->say