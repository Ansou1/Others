/**
   * Déclaration de l'application
   */
  var app = angular.module('budjet', [
      // Dépendances du "module"
      'ngRoute',
      'routeControllers'
  ]);

/**
   * Configuration du module principal : routeApp
   */
  app.config(['$routeProvider',
      function($routeProvider) {

          // Système de routage
          $routeProvider
          .when('/home', {
              templateUrl: 'partials/home.html',
              controller: 'homeCtrl'
          })
          .when('/account', {
              templateUrl: 'partials/account.html',
              controller: 'accountCtrl'
          })
          .when('/income', {
              templateUrl: 'partials/income.html',
              controller: 'incomeCtrl'
          })
          .when('/regularExpense',{
            templateUrl: 'partials/regularExpense.html',
            controller: "regularExpenseCtrl"
          })
          .when('/spent', {
              templateUrl: 'partials/spent.html',
              controller: 'spentCtrl'
          })
          .otherwise({
             redirectTo: '/home'
         });
      }
  ]);

var routeControllers = angular.module('routeControllers', []);

document.addEventListener("deviceready", function() {
    // retrieve the DOM element that had the ng-app attribute
    var domElement = document.getElementById("body");
    angular.bootstrap(domElement, ["budjet"]);
}, false);
