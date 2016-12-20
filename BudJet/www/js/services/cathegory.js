app.factory("cathegories", [function(){
	var data = [];
	var sdo = {
		add : function(obj, success, failure){
	    data.push(obj);
	  	saveData(config.files.cathegories, data, function(){
	  			success(obj);
	  		}, failure);
	  },

	  delete : function(name, success, failure){
	    for(var i =0;i<data.length;i++){
	      if (data[i].name == name){
	        data.splice(i, 1);
	        saveData(config.files.cathegories, data, function(){
	            success(obj);
	          }, failure);
	          return;
	      }
	    }
	  },

	  update : function(name, obj, success, failure){
	    var updated = false;
	    for(var i =0;i<data.length;i++){
	  		if (data[i].name == name){
	        updated = true;
	        if (obj.name != null) data[i].name = obj.name;
	        if (obj.color != null) data[i].color = obj.color;
	        if (obj.colorCode != null) data[i].colorCode = obj.colorCode;
	        if (obj.icon != null) data[i].icon = obj.icon;
	  		}
	  	}
	    if (updated){
	      saveData(config.files.cathegories, data, function(){
	    			success(obj);
	    		}, failure);
	    }
	  },

	  get : function(name){
	    for(var i =0;i<data.length;i++){
	  		if (data[i].name == name){
	  			return data[i];
	  		}
	  	}
	  	return null;
	  },

		getCathegories : function(){
			return data;
		},

	  load : function(success){
	    loadData(config.files.cathegories, function(result){
	      if (result == null){
	        result = [
						{name:"food",color:"green",colorCode:"#4caf50",icon:"local_dining"},
  						{name:"clothe",color:"lime darken-4",colorCode:"#827717",icon:"shopping_cart"},
						{name:"care",color:"teal accent-3",colorCode:"#1de9b6",icon:"favorite"},
						{name:"transportation",color:"light-blue darken-3",colorCode:"#0277bd",icon:"directions_bus"},
						{name:"passtime",color:"red",colorCode:"#f44336",icon:"insert_emoticon"},
						{name:"home",color:"indigo lighten-1",colorCode:"#5c6bc0",icon:"home"}
					];
	      }
	      data = result;
	      console.log(data);
	      success();
	    });
	  }
	};
	return sdo;
}]);
