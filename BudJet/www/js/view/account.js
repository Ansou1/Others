var addAccountView = {
  var accountElements = [], //Accounts to be displayed
  var listElement = null;

  add : function(account){
    //$("<div></div").loadTemplate("template/account/listElement.html", account);
    var list = $("#accounts");

    var li = $( document.createElement('li') );
    li.attr('id', id);
    li.addClass("collection-item");
    var element = $( document.createElement('div') );
    element.text(account.name + " " + account.money + ' $');

    var icon1 = $( document.createElement('i') );
    icon1.addClass("material-icons");
    icon1.text("delete_forever");
    icon1.click(function(){
      deleteAccount(account.id);
    });
    var icon2 = $( document.createElement('i') );
    icon2.addClass("material-icons");
    icon2.text("mode_edit");
    icon2.click(function(){
      updateAccount(account.id);
    });

    var button1 = $( document.createElement('a') );
    button1.addClass('secondary-content');
    var button2 = $( document.createElement('a') );
    button2.addClass('secondary-content');
    button1.append(icon1);
    button2.append(icon2);

    element.append(button1);
    element.append(button2);
    li.append(element);
    list.append(li);
  },

  delete : function(id){
    var li = $('#'+id);
    li.empty().remove();
  },

  update : function(account){
    $("#"+account.id).children().contents().get(0).nodeValue = account.name + " " + account.money +" €";
  },

  displayList : function(){
    var len = this.accountElements.length;
    for (var i = 0; i < len; i++){
      createLi(gdata.accounts[i].name, gdata.accounts[i].money, gdata.accounts[i].id);
    }
  },

  setAccounts : function(){
    this.accountElements = accounts.data;
  },

  displayForm : function(onSubmit){
    showForm();
    $('#addAccountForm').unbind();
    $('#addAccountForm').submit(onSubmit);
  },

  showForm : function(){$('#modal1').show();},
  hideForm : function(){$('#modal1').hide();}
}
