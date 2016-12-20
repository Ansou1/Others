function account(id, name, money, description) {
  this.id = (id == undefined || id === null) ? uniqid() : id;//string
  this.name = (name == undefined || name === null) ? "" : name;//string
  this.money = (money == undefined || money === null) ? 0.00 : Number(money);//string
  this.description = (description == undefined || description === null) ? "" : description;//string
}

routeControllers.controller('accountCtrl', ['$scope', 'accounts', function($scope, accounts){
  $('.button-collapse').sideNav({
      menuWidth: 300, // Default is 240
      edge: 'left', // Choose the horizontal origin
      closeOnClick: true // Closes side-nav on <a> clicks, useful for Angular/Meteor
  });
  $scope.accounts = accounts.getAccounts();
  $scope.showAddForm = function(){
    $('#modal1').show();
    $scope.account = new account();
  }

  $scope.showUpdateForm = function(account){
    $('#modal2').show();
    $scope.account = account;
  }

  $scope.create = function(acc){
    console.log("create account form value :", acc);
    var a = new account(null, acc.name, acc.money, acc.description);
    accounts.add(a,
      function(){$('#modal1').hide();},
      function(){console.log("Error : create Account failed");}
    );
  }

  $scope.delete = function(account){
    accounts.delete(account.id,
      function(){},
      function(){console.log("Error : delete Account failed");}
    );
  }

  $scope.update = function(account){
    accounts.update(account,
      function(){$('#modal2').hide();},
      function(){console.log("Error : update account failed");}
    );
  }
}]);
