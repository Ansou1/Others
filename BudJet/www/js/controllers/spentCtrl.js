function spent(id, name, cost, account, cathegory, date){
		this.id = (id == undefined || id === null) ? uniqid() : id;//string
    this.name = (name == undefined || name === null) ? "" : name;//string
    this.cost = (cost == undefined || cost === null) ? 0.0 : cost;//string
    this.account = (account == undefined || account === null) ? null : account;//string
    this.cathegory = (cathegory == undefined || cathegory === null) ? null : cathegory;//string
    this.date = (date == undefined || date === null) ? new Date() : new Date(date);//string
}

routeControllers.controller('spentCtrl', ['$scope', 'accounts', 'spents', 'cathegories', function($scope, accounts, spents, cathegories){
	$('.button-collapse').sideNav({
			menuWidth: 300, // Default is 240
			edge: 'left', // Choose the horizontal origin
			closeOnClick: true // Closes side-nav on <a> clicks, useful for Angular/Meteor
	});
	displayList();
	$scope.hide = function(id){
		$(id).hide();
	}

	$scope.showAddForm = function(){
    	$('#modalNewSpent').show();
    	var s = modelToDisplay(new spent());
    	$scope.spent = s;
  	}

  	$scope.showUpdateForm = function(spent){
    	$('#modalUpdateSpent').show();
    	$scope.spent = spent;
  	}

  	$scope.delete = function(spent){
    	spents.delete(spent.id, function(){
    		var len = $scope.spents.length;
        $scope.$apply(function(){
          for (var i=0;i<len;i++){
            if (spent.id == $scope.spents[i].id){
              $scope.spents.splice(i, 1);
            }
          }
        });
        Materialize.toast(spent.name+" deleted", 2000);
    	}, function(){
    		console.log("delete spent failed");
    	});
  	}

  	$scope.create = function(obj){
      var s = new spent(null, obj.name, obj.cost, obj.account, obj.cathegory, obj.date);
    	spents.add(s, function(){
        $scope.$apply(function(){
          $scope.spents.push(modelToDisplay(s));
        });
    		$('#modalNewSpent').hide();
        Materialize.toast(spent.name+" created", 2000);
    	}, function(){
    		console.log("create spent failed");
    	});
  	}

  	$scope.update = function(spent){
    	spents.update(spent, function(){
    		$('#modalUpdateSpent').hide();
        Materialize.toast(spent.name+" updated", 2000);
    	}, function(){
    		console.log("create spent failed");
    	});
  	}

  	function displayList(){
			$scope.cathegories = cathegories.getCathegories();
			$scope.accounts = accounts.getAccounts();
  		$scope.spents = [];
  		var list = spents.getSpents();
  		for (var i=0;i<list.length;i++){
  			$scope.spents.push(modelToDisplay(list[i]));
  		}
			$(document).ready(function() {
    		$('select').material_select();
  		});
			$(document).ready(function(){
        $('.collapsible').collapsible();
      });
  	}

  	function modelToDisplay(s){
  		var ss = new spent(s.id, s.name, s.cost, s.account, s.cathegory, s.date);
  		ss.account = accounts.get(ss.account);
  		ss.cathegory = cathegories.get(ss.cathegory);
  		return ss;
  	}
}]);
