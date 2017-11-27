#include "main_window.h"


int Main_window::select_from_vector(std::vector<std::string> names, std::string title) {

	Gtk::Dialog dialog_index{"Select " + title, *this};
	const int WIDTH = 15;

	// Container
	Gtk::HBox b_index;

	Gtk::Label l_index{title + ":"};
	l_index.set_width_chars(WIDTH);
	b_index.pack_start(l_index, Gtk::PACK_SHRINK);

	// Create dropdown list
	Gtk::ComboBoxText c_index;
	c_index.set_size_request(WIDTH*10);
	for (std::string s : names) c_index.append(s);
	b_index.pack_start(c_index, Gtk::PACK_SHRINK);
	dialog_index.get_vbox()->pack_start(b_index, Gtk::PACK_SHRINK);

	// Show dialog_index
	dialog_index.add_button("Cancel", 0);
	dialog_index.add_button("OK", 1);
	dialog_index.show_all();
	if (dialog_index.run() != 1) return -1;

	int index = c_index.get_active_row_number();

	dialog_index.close();

	return index;
}

int Main_window::select_from_grid(std::vector<std::string> names, std::vector<std::string> path, std::string title) {

	Gtk::Dialog gdlg{"Select " + title, *this};
	const int WIDTH = 15;
	int counter = 0;

	int rows = names.size() / 3;

	std::cout << "rows:" << rows << '\n';

	Gtk::Grid grid;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < rows+1; j++) {
			if(counter<names.size()) {
				auto button = Gtk::manage(new Gtk::Button(names[j+i*3]));
				//button->signal_clicked(j+i*3);
				grid.attach(*button, i, j, 1, 1);
			}
			counter++;
		}
	}

	gdlg.add_button("Cancel", -1);

	gdlg.get_vbox()->pack_start(grid, Gtk::PACK_SHRINK);

	gdlg.show_all();
	gdlg.run();

	return 1;

}
