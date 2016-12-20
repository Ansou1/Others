var addSpentView = {
  listElement : null,
  list : $("#spents-list"),
  load : function (finished){
    var e = $(document.createElement('div')).load("addSpentListElement.html", function(){
      listElement = e.first();
      finished();
    });
  },

  add : function (spent){
    //$("<div></div>").loadTemplate('template/spent/addListElement', spent);
    var element = listElement.clone();
    $(element.children()[0].children[0]).text(spent.cathegory.icon);
    $(element.children()[0].children[1]).text(spent.name);
    $(element.children()[0].children[2]).text(spent.cost + "€");
    $(element.children()[1].children[0].children[0]).text(spent.date);
    $(element.children()[1].children[0].children[3]).text(spent.account);
    list.add(element);
  },

  update : function (spent){
    var element = $("#"+spent.id);
    //maybe something more to get to the element
    $(element.children()[0].children[0]).text(spent.cathegory.icon);
    $(element.children()[0].children[1]).text(spent.name);
    $(element.children()[0].children[2]).text(spent.cost + "€");
    $(element.children()[1].children[0].children[0]).text(spent.date);
    $(element.children()[1].children[0].children[3]).text(spent.account);
  },

  delete : function(id){
    var li = $('#'+id);
    li.empty().remove();
  },

  dislay : function (){
    var len = spents.data.length;
  	for (var i = 0; i < len; i++){
  		this.add(spents.data.spents[i]);
  	}
  },

  createOption : function(value, content){
  	var option = $(document.createElement('option'));
  	option.attr('value', value);
  	option.text(content);
  	return option;
  },

  fillOptions : function(){
  		var accounts = $('#accountSelect');
  		var cathegories = $('#cathegorySelect');
  		accounts.append(createOption("0", "none"));
  		for (var i =0;i<gdata.accounts.length;i++){
  			accounts.append(createOption(gdata.accounts[i].id, gdata.accounts[i].name));
  		}
  		for (var i =0;i<gdata.cathegories.length;i++){
  			cathegories.append(createOption(gdata.cathegories[i].id, gdata.cathegories[i].name));
  		}
  		$('select').material_select();
  },

  displayForm : function(onSubmit){
    showForm();
    $('#newSpentForm').unbind();
    $('#newSpentForm').submit(onSubmit);
  },

  showForm : function(){$('#modal1').show();},
  hideForm : function(){$('#modal1').hide();}

}
