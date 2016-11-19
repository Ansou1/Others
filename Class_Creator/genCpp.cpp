#include			<fstream>
#include			"HomeWindow.hpp"

static bool			createFile(QString const& name, QString const& path, QString& code)
{
  std::ofstream                 file((path.toStdString() + "/" + name.toStdString() + ".cpp").c_str(), std::ios::out | std::ios::trunc);

  if (!file)
    return (false);
  file << code.toStdString();
  file.close();

  return (true);
}

bool                            HomeWindow::genCpp()
{
  if (getName()->text().isEmpty() || (!getConstruct()->isChecked() && !getDestruct()->isChecked()))
    return (false);

  QString                       code;

  if (getComments()->isChecked())
    fillComments(code, 0);
  code += "#include			\"" + getName()->text() + ".hpp\"\n\n";
  if (getConstruct()->isChecked())
    code += getName()->text() + "::" + getName()->text() + "()\n{\n}\n\n";
  if (getDestruct()->isChecked())
    code += getName()->text() + "::~" + getName()->text() + "()\n{\n}\n\n";

  if (!createFile(getName()->text(), getDirectory()->text(),code))
    return (false);

  return (true);
}
