#include			<QApplication>
#include			"HomeWindow.hpp"

static void			noGraphMode(char** av, HomeWindow& home)
{
  home.getName()->insert(av[1]);
  if (av[2] && std::string(av[2]) != "-c" 
      && std::string(av[2]) != "-d" 
      && std::string(av[2]) != "-h")
    home.getPrimClass()->insert(av[2]);
  for (int a = 2; av[a]; a += 1)
    {
      if (std::string(av[a]) == "-c")
	home.getConstruct()->setChecked(false);
      if (std::string(av[a]) == "-d")
	home.getDestruct()->setChecked(false);
      if (std::string(av[a]) == "-h")
	home.getComments()->setChecked(false);
    }
  home.genNoGraph();
}

int				main(int ac, char** av)
{
  QApplication		app(ac, av);
  HomeWindow		home;

  if (ac == 1)
    {
      home.show();
      return (app.exec());
    }
  else
    noGraphMode(av, home);

  return (0);
}
