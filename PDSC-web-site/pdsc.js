$(document).ready(function()
{
    $(window).scroll(function()
    {
        if (this.scrollY > 20)
        {
            $('.menu').addClass(" chipakja");
        }
        else
        {
            $('.menu').removeClass(" chipakja");
        }
    })

        // gotta understand this
   
});