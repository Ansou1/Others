app.factory("spents", ["accounts", function(accounts){
	var data = [];
	var sdo = {
		add : function(obj, success, failure){
		    if (obj.id == undefined || obj.id == null) obj.id = uniqid();
		    var account = accounts.get(obj.account);
		    if (account)
		    	account.money = account.money - obj.cost;
		    data.push(obj);
		    saveData(config.files.spents, data, function(){
		      saveData(config.files.accounts, accounts.getAccounts(), function(){
		        success(obj);
		      }, failure);
		    }, failure);
	  	},

	  	delete : function(id, success, failure){
		    for(var i =0;i<data.length;i++){
		      if (data[i].id == id){
		        data.splice(i, 1);
		        saveData(config.files.spents, data, function(){
		            success();
		          }, failure);
		          return;
		      }
		    }
	  	},

	  	update : function(spent, success, failure){
		    var a = this.get(spent.id);
		    if (a === null) return;
		    if (spent.name != null) a.name = spent.name;
		    if (spent.cost != null) a.cost = spent.cost;
		    if (spent.account != undefined) a.account = spent.account;
		    if (spent.cathegory != undefined) a.cathegory = spent.cathegory;
		    if (spent.date != null) a.date = new Date(spent.date);

		    saveData(config.files.spents, data, function(){
		        success(spent);
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

		getSpents : function(){
			return data;
		},

	  	load : function(success){
		    loadData(config.files.spents, function(result){
		      if (result == null) result = [];
		      for (var i =0;i<result.length;i++){
						result[i].date = new Date(result[i].date);
					}
		      data = result;
		      console.log(data);
		      success();
		    });
	  	},

	  	sortByDate : function(){
		    data.sort(function(a,b){
		      return a.date.compare(a.date,b.date);
		    });
	  	}
	};
	return sdo;
}]);
