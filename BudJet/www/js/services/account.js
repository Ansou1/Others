app.factory("accounts", [function(){
	var data = [];
	var sdo = {
		add : function(obj, success, failure){
	    if (obj.id == null) obj.id = uniqid();
	    data.push(obj);
	  	saveData(config.files.accounts, data, function(){
	  			success(obj);
	  		}, failure);
	  },

		get : function(id){
		    for(var i =0;i<data.length;i++){
		      if (data[i].id == id){
		      return data[i];
		      }
		    }
		    return null;
	  	},

	  delete : function(id, success, failure){
	    for(var i =0;i<data.length;i++){
	      if (data[i].id == id){
	        data.splice(i, 1);
	        saveData(config.files.accounts, data, function(){
	            success();
	          }, failure);
	          return;
	      }
	    }
	  },

	  update : function(obj, success, failure){
	    var a = this.get(obj.id);
	    if (a === null) return;
	    if (obj.name != null) a.name = obj.name;
	    if (obj.money != null) a.money = obj.money;
	    if (obj.description != null) a.description = obj.description;
	    saveData(config.files.accounts, data, function(){
	        success(obj);
	      }, failure);
	  },

	  load : function(success){
	    loadData(config.files.accounts, function(result){
	      data = result || [];
	      console.log(data);
	      success();
	    });

	  },

		getAccounts : function(){
			return data;
		}
	};
	return sdo;
}]);
