/*
 *  This file is part of RawTherapee.
 *
 *  Copyright (c) 2021 Lawrence Lee
 *
 *  RawTherapee is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  RawTherapee is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RawTherapee.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <unordered_set>

#include "guiutils.h"
#include "options.h"
#include "rtimage.h"
#include "toollocationpref.h"
#include "toolpanelcoord.h"

using Tool = ToolPanelCoordinator::Tool;
using Favorites = std::unordered_set<Tool, ScopedEnumHash>;

namespace
{

std::string getToolName(Tool tool)
{
    switch (tool) {
        case Tool::TONE_CURVE:
            return "tonecurve";
        case Tool::SHADOWS_HIGHLIGHTS:
            return "shadowshighlights";
        case Tool::IMPULSE_DENOISE:
            return "impulsedenoise";
        case Tool::DEFRINGE_TOOL:
            return "defringe";
        case Tool::SPOT:
            return "spot";
        case Tool::DIR_PYR_DENOISE:
            return "dirpyrdenoise";
        case Tool::EPD:
            return "epd";
        case Tool::SHARPENING_TOOL:
            return "sharpening";
        case Tool::LOCAL_CONTRAST:
            return "localcontrast";
        case Tool::SHARPEN_EDGE:
            return "sharpenedge";
        case Tool::SHARPEN_MICRO:
            return "sharpenmicro";
        case Tool::L_CURVE:
            return "labcurves";
        case Tool::RGB_CURVES:
            return "rgbcurves";
        case Tool::COLOR_TONING:
            return "colortoning";
        case Tool::LENS_GEOM:
            return "lensgeom";
        case Tool::LENS_PROF:
            return "lensprof";
        case Tool::DISTORTION:
            return "distortion";
        case Tool::ROTATE:
            return "rotate";
        case Tool::VIBRANCE:
            return "vibrance";
        case Tool::COLOR_APPEARANCE:
            return "colorappearance";
        case Tool::WHITE_BALANCE:
            return "whitebalance";
        case Tool::VIGNETTING:
            return "vignetting";
        case Tool::RETINEX_TOOL:
            return "retinex";
        case Tool::GRADIENT:
            return "gradient";
        case Tool::LOCALLAB:
            return "locallab";
        case Tool::PC_VIGNETTE:
            return "pcvignette";
        case Tool::PERSPECTIVE:
            return "perspective";
        case Tool::CA_CORRECTION:
            return "cacorrection";
        case Tool::CH_MIXER:
            return "chmixer";
        case Tool::BLACK_WHITE:
            return "blackwhite";
        case Tool::RESIZE_TOOL:
            return "resize";
        case Tool::PR_SHARPENING:
            return "prsharpening";
        case Tool::CROP_TOOL:
            return "crop";
        case Tool::ICM:
            return "icm";
        case Tool::WAVELET:
            return "wavelet";
        case Tool::DIR_PYR_EQUALIZER:
            return "dirpyrdenoise";
        case Tool::HSV_EQUALIZER:
            return "hsvequalizer";
        case Tool::FILM_SIMULATION:
            return "filmsimulation";
        case Tool::SOFT_LIGHT:
            return "softlight";
        case Tool::DEHAZE:
            return "dehaze";
        case Tool::SENSOR_BAYER:
            return "sensorbayer";
        case Tool::SENSOR_XTRANS:
            return "sensorxtrans";
        case Tool::BAYER_PROCESS:
            return "bayerprocess";
        case Tool::XTRANS_PROCESS:
            return "xtransprocess";
        case Tool::BAYER_PREPROCESS:
            return "bayerpreprocess";
        case Tool::PREPROCESS:
            return "preprocess";
        case Tool::DARKFRAME_TOOL:
            return "darkframe";
        case Tool::FLATFIELD_TOOL:
            return "flatfield";
        case Tool::RAW_CA_CORRECTION:
            return "rawcacorrection";
        case Tool::RAW_EXPOSURE:
            return "rawexposure";
        case Tool::PREPROCESS_WB:
            return "preprocesswb";
        case Tool::BAYER_RAW_EXPOSURE:
            return "bayerrawexposure";
        case Tool::XTRANS_RAW_EXPOSURE:
            return "xtransrawexposure";
        case Tool::FATTAL:
            return "fattal";
        case Tool::FILM_NEGATIVE:
            return "filmnegative";
        case Tool::PD_SHARPENING:
            return "capturesharpening";
    };
    return "";
};

Glib::ustring getToolPanelTitleKey(ToolPanelCoordinator::Panel panel)
{
    switch (panel) {
        case ToolPanelCoordinator::Panel::FAVORITE:
            return "MAIN_TAB_FAVORITES";
        case ToolPanelCoordinator::Panel::EXPOSURE:
            return "MAIN_TAB_EXPOSURE";
        case ToolPanelCoordinator::Panel::DETAILS:
            return "MAIN_TAB_DETAIL";
        case ToolPanelCoordinator::Panel::COLOR:
            return "MAIN_TAB_COLOR";
        case ToolPanelCoordinator::Panel::ADVANCED:
            return "MAIN_TAB_ADVANCED";
        case ToolPanelCoordinator::Panel::LOCALLAB:
            return "MAIN_TAB_LOCALLAB";
        case ToolPanelCoordinator::Panel::TRANSFORM_PANEL:
            return "MAIN_TAB_TRANSFORM";
        case ToolPanelCoordinator::Panel::RAW:
            return "MAIN_TAB_RAW";
    }
    return "";
}

Glib::ustring getToolTitleKey(Tool tool)
{
    using Tool = Tool;
    switch (tool) {
        case Tool::TONE_CURVE:
            return "TP_EXPOSURE_LABEL";
        case Tool::SHADOWS_HIGHLIGHTS:
            return "TP_SHADOWSHLIGHTS_LABEL";
        case Tool::IMPULSE_DENOISE:
            return "TP_IMPULSEDENOISE_LABEL";
        case Tool::DEFRINGE_TOOL:
            return "TP_DEFRINGE_LABEL";
        case Tool::SPOT:
            return "TP_SPOT_LABEL";
        case Tool::DIR_PYR_DENOISE:
            return "TP_DIRPYRDENOISE_LABEL";
        case Tool::EPD:
            return "TP_EPD_LABEL";
        case Tool::SHARPENING_TOOL:
            return "TP_SHARPENING_LABEL";
        case Tool::LOCAL_CONTRAST:
            return "TP_LOCALCONTRAST_LABEL";
        case Tool::SHARPEN_EDGE:
            return "TP_SHARPENEDGE_LABEL";
        case Tool::SHARPEN_MICRO:
            return "TP_SHARPENMICRO_LABEL";
        case Tool::L_CURVE:
            return "TP_LABCURVE_LABEL";
        case Tool::RGB_CURVES:
            return "TP_RGBCURVES_LABEL";
        case Tool::COLOR_TONING:
            return "TP_COLORTONING_LABEL";
        case Tool::LENS_GEOM:
            return "TP_LENSGEOM_LABEL";
        case Tool::LENS_PROF:
            return "TP_LENSPROFILE_LABEL";
        case Tool::DISTORTION:
            return "TP_DISTORTION_LABEL";
        case Tool::ROTATE:
            return "TP_ROTATE_LABEL";
        case Tool::VIBRANCE:
            return "TP_VIBRANCE_LABEL";
        case Tool::COLOR_APPEARANCE:
            return "TP_COLORAPP_LABEL";
        case Tool::WHITE_BALANCE:
            return "TP_WBALANCE_LABEL";
        case Tool::VIGNETTING:
            return "TP_VIGNETTING_LABEL";
        case Tool::RETINEX_TOOL:
            return "TP_RETINEX_LABEL";
        case Tool::GRADIENT:
            return "TP_GRADIENT_LABEL";
        case Tool::LOCALLAB:
            return "TP_LOCALLAB_LABEL";
        case Tool::PC_VIGNETTE:
            return "TP_PCVIGNETTE_LABEL";
        case Tool::PERSPECTIVE:
            return "TP_PERSPECTIVE_LABEL";
        case Tool::CA_CORRECTION:
            return "TP_CACORRECTION_LABEL";
        case Tool::CH_MIXER:
            return "TP_CHMIXER_LABEL";
        case Tool::BLACK_WHITE:
            return "TP_BWMIX_LABEL";
        case Tool::RESIZE_TOOL:
            return "TP_RESIZE_LABEL";
        case Tool::PR_SHARPENING:
            return "TP_PRSHARPENING_LABEL";
        case Tool::CROP_TOOL:
            return "TP_CROP_LABEL";
        case Tool::ICM:
            return "TP_ICM_LABEL";
        case Tool::WAVELET:
            return "TP_WAVELET_LABEL";
        case Tool::DIR_PYR_EQUALIZER:
            return "TP_DIRPYRDENOISE_LABEL";
        case Tool::HSV_EQUALIZER:
            return "TP_HSVEQUALIZER_LABEL";
        case Tool::FILM_SIMULATION:
            return "TP_FILMSIMULATION_LABEL";
        case Tool::SOFT_LIGHT:
            return "TP_SOFTLIGHT_LABEL";
        case Tool::DEHAZE:
            return "TP_DEHAZE_LABEL";
        case Tool::SENSOR_BAYER:
            return "TP_RAW_SENSOR_BAYER_LABEL";
        case Tool::SENSOR_XTRANS:
            return "TP_RAW_SENSOR_XTRANS_LABEL";
        case Tool::BAYER_PROCESS:
            return "TP_RAW_LABEL";
        case Tool::XTRANS_PROCESS:
            return "TP_RAW_LABEL";
        case Tool::BAYER_PREPROCESS:
            return "TP_PREPROCESS_LABEL";
        case Tool::PREPROCESS:
            return "TP_PREPROCESS_LABEL";
        case Tool::DARKFRAME_TOOL:
            return "TP_DARKFRAME_LABEL";
        case Tool::FLATFIELD_TOOL:
            return "TP_FLATFIELD_LABEL";
        case Tool::RAW_CA_CORRECTION:
            return "TP_RAWCACORR_LABEL";
        case Tool::RAW_EXPOSURE:
            return "TP_EXPOS_WHITEPOINT_LABEL";
        case Tool::PREPROCESS_WB:
            return "TP_PREPROCWB_LABEL";
        case Tool::BAYER_RAW_EXPOSURE:
            return "TP_EXPOS_BLACKPOINT_LABEL";
        case Tool::XTRANS_RAW_EXPOSURE:
            return "TP_EXPOS_BLACKPOINT_LABEL";
        case Tool::FATTAL:
            return "TP_TM_FATTAL_LABEL";
        case Tool::FILM_NEGATIVE:
            return "TP_FILMNEGATIVE_LABEL";
        case Tool::PD_SHARPENING:
            return "TP_PDSHARPENING_LABEL";
    };
    return "";
}

class ListEditButtons : public Gtk::Box
{
private:
    Gtk::TreeView &list;
    Glib::RefPtr<Gtk::ListStore> listStore;
    Gtk::Button buttonUp;
    Gtk::Button buttonDown;
    Gtk::Button buttonRemove;

    sigc::signal<void, const std::vector<Gtk::TreeModel::Path>> signalRowsPreErase;

    void onButtonDownPressed();
    void onButtonRemovePressed();
    void onButtonUpPressed();
    void onListSelectionChanged();
    void updateButtonSensitivity();

public:
    explicit ListEditButtons(Gtk::TreeView &list, Glib::RefPtr<Gtk::ListStore> listStore);

    sigc::signal<void, const std::vector<Gtk::TreeModel::Path>> getSignalRowsPreErase();
};

class FavoritesColumns : public Gtk::TreeModelColumnRecord
{
public:
    Gtk::TreeModelColumn<Glib::ustring> toolName;
    Gtk::TreeModelColumn<Tool> tool;

    FavoritesColumns()
    {
        add(toolName);
        add(tool);
    }
};

class ToolListColumns : public Gtk::TreeModelColumnRecord
{
public:
    Gtk::TreeModelColumn<Glib::ustring> toolName;
    Gtk::TreeModelColumn<Tool> tool;
    Gtk::TreeModelColumn<bool> isFavorite;
    Gtk::TreeModelColumn<bool> isEditable;

    ToolListColumns()
    {
        add(toolName);
        add(tool);
        add(isFavorite);
        add(isEditable);
    }
};

ListEditButtons::ListEditButtons(Gtk::TreeView &list, Glib::RefPtr<Gtk::ListStore> listStore) :
    Gtk::Box(Gtk::Orientation::ORIENTATION_VERTICAL),
    list(list),
    listStore(listStore)
{
    assert(list.get_model() == listStore);

    // Set button images.
    RTImage *image_button_up = Gtk::manage(new RTImage("arrow-up-small.png"));
    RTImage *image_button_down = Gtk::manage(new RTImage("arrow-down-small.png"));
    RTImage *image_button_remove = Gtk::manage(new RTImage("remove-small.png"));
    buttonUp.set_image(*image_button_up);
    buttonDown.set_image(*image_button_down);
    buttonRemove.set_image(*image_button_remove);

    // Connect signals for changing button sensitivity.
    const auto on_list_sel_changed_fun = sigc::mem_fun(
        *this, &ListEditButtons::onListSelectionChanged);
    const auto on_row_deleted_fun = sigc::hide(on_list_sel_changed_fun);
    const auto on_row_inserted_fun = sigc::hide(on_row_deleted_fun);
    list.get_selection()->signal_changed().connect(on_list_sel_changed_fun);
    listStore->signal_row_deleted().connect(on_row_deleted_fun);
    listStore->signal_row_inserted().connect(on_row_inserted_fun);

    // Connect signals for buttons.
    buttonUp.signal_pressed().connect(sigc::mem_fun(
        *this, &ListEditButtons::onButtonUpPressed));
    buttonDown.signal_pressed().connect(sigc::mem_fun(
        *this, &ListEditButtons::onButtonDownPressed));
    buttonRemove.signal_pressed().connect(sigc::mem_fun(
        *this, &ListEditButtons::onButtonRemovePressed));

    updateButtonSensitivity();

    add(buttonUp);
    add(buttonDown);
    add(buttonRemove);
}

void ListEditButtons::onButtonDownPressed()
{
    const auto list_children = listStore->children();
    const std::vector<Gtk::TreeModel::Path> selected =
        list.get_selection()->get_selected_rows();

    if (selected.size() != 1) { // Only one can be selected.
        return;
    }

    auto selected_row_iter = listStore->get_iter(selected[0]);
    auto next_row_iter = selected_row_iter;
    next_row_iter++;

    if (next_row_iter == list_children.end()) { // Can't be last row.
        return;
    }

    listStore->iter_swap(selected_row_iter, next_row_iter);
    updateButtonSensitivity();
}

void ListEditButtons::onButtonRemovePressed()
{
    const std::vector<Gtk::TreeModel::Path> selected_paths =
        list.get_selection()->get_selected_rows();
    std::vector<Gtk::TreeModel::RowReference> selected;

    // Get row references, which are valid until the row is removed.
    for (const auto & row_path : selected_paths) {
        selected.push_back(Gtk::TreeModel::RowReference(listStore, row_path));
    }

    signalRowsPreErase.emit(selected_paths);

    for (const auto & row_ref : selected) {
        const auto row_path = row_ref.get_path();
        if (row_path) {
            listStore->erase(listStore->get_iter(row_path));
        }
    }

    updateButtonSensitivity();
}

void ListEditButtons::onButtonUpPressed()
{
    const auto list_children = listStore->children();
    const std::vector<Gtk::TreeModel::Path> selected =
        list.get_selection()->get_selected_rows();

    if (selected.size() != 1) { // Only one can be selected.
        return;
    }

    auto selected_row_iter = listStore->get_iter(selected[0]);

    if (selected_row_iter == list_children.begin()) { // Can't be first row.
        return;
    }

    auto prev_row_iter = selected_row_iter;
    prev_row_iter--;
    listStore->iter_swap(selected_row_iter, prev_row_iter);
    updateButtonSensitivity();
}

void ListEditButtons::onListSelectionChanged()
{
    updateButtonSensitivity();
}

void ListEditButtons::updateButtonSensitivity()
{
    assert(list.get_model() == listStore);

    const std::vector<Gtk::TreeModel::Path> selected =
        list.get_selection()->get_selected_rows();

    // Update sensitivity of the move up/down buttons.
    if (selected.size() != 1) {
        // Items can only be moved if one row is selected.
        buttonDown.set_sensitive(false);
        buttonUp.set_sensitive(false);
    } else {
        auto selected_row_iter = list.get_model()->get_iter(selected[0]);
        const auto list_children = listStore->children();
        buttonUp.set_sensitive(!selected_row_iter->equal(list_children.begin()));
        buttonDown.set_sensitive(!(++selected_row_iter)->equal(list_children.end()));
    }

    // Update sensitivity of the remove button.
    buttonRemove.set_sensitive(selected.size() > 0);
}

sigc::signal<void, const std::vector<Gtk::TreeModel::Path>>
ListEditButtons::getSignalRowsPreErase()
{
    return signalRowsPreErase;
}

}

struct ToolLocationPreference::Impl {
    static std::unordered_map<std::string, Tool> toolNamesReverseMap;

    Options &options;

    // Tool list.
    ToolListColumns toolListColumns;
    Glib::RefPtr<Gtk::TreeStore> toolListModelPtr;
    Gtk::CellRendererToggle toolListCellRendererFavorite;
    Gtk::CellRendererText toolListCellRendererToolName;
    Gtk::TreeViewColumn toolListViewColumnFavorite;
    Gtk::TreeViewColumn toolListViewColumnToolName;
    Gtk::TreeView *toolListViewPtr;
    std::unordered_map<Tool, Gtk::TreeModel::iterator, ScopedEnumHash>
        toolListToolToRowIterMap;

    // Favorites list.
    FavoritesColumns favoritesColumns;
    Glib::RefPtr<Gtk::ListStore> favoritesModelPtr;
    Gtk::CellRendererText favoritesCellRendererToolName;
    Gtk::TreeViewColumn favoritesViewColumnToolName;
    Gtk::TreeView *favoritesViewPtr;
    ListEditButtons favoritesListEditButtons;

    explicit Impl(Options &options);

    void addToolListRowGroup(
        const std::vector<ToolPanelCoordinator::ToolTree> &tools,
        const Gtk::TreeIter &parentRowIter,
        const Favorites &favorites);
    void favoriteToggled(const Glib::ustring &row_path);
    Tool getToolFromName(const std::string &name) const;
    void initFavoritesRows(const std::vector<Tool> &favorites);
    void initToolListRows(const std::vector<Tool> &favorites);
    void onFavoritesRowsPreRemove(const std::vector<Gtk::TreeModel::Path> paths);
    std::vector<Tool> toolNamesToTools(
        const std::vector<Glib::ustring> &tool_names) const;
    void updateOptions();
};

std::unordered_map<std::string, Tool>
    ToolLocationPreference::Impl::toolNamesReverseMap;

ToolLocationPreference::Impl::Impl(Options &options) :
    options(options),

    toolListModelPtr(Gtk::TreeStore::create(toolListColumns)),
    toolListViewColumnFavorite(
        Gtk::TreeViewColumn(M("PREFERENCES_TOOLPANEL_FAVORITE"))),
    toolListViewColumnToolName(
        Gtk::TreeViewColumn(M("PREFERENCES_TOOLPANEL_TOOL"))),
    toolListViewPtr(Gtk::manage(new Gtk::TreeView(toolListModelPtr))),

    favoritesModelPtr(Gtk::ListStore::create(favoritesColumns)),
    favoritesViewColumnToolName(
        Gtk::TreeViewColumn(M("PREFERENCES_TOOLPANEL_TOOL"))),
    favoritesViewPtr(Gtk::manage(new Gtk::TreeView(favoritesModelPtr))),
    favoritesListEditButtons(*favoritesViewPtr, favoritesModelPtr)
{
    const std::vector<Tool> favorites = toolNamesToTools(options.favorites);

    // Tool list.
    toolListViewPtr->append_column(toolListViewColumnToolName);
    toolListViewColumnToolName.pack_start(toolListCellRendererToolName);
    toolListViewColumnToolName.set_expand();
    toolListViewColumnToolName.set_renderer(
        toolListCellRendererToolName, toolListColumns.toolName);
    toolListViewPtr->append_column(toolListViewColumnFavorite);
    toolListViewColumnFavorite.pack_start(toolListCellRendererFavorite);
    toolListViewColumnFavorite.set_expand(false);
    toolListViewColumnFavorite.set_renderer(
        toolListCellRendererFavorite, toolListColumns.isFavorite);
    toolListViewColumnFavorite.add_attribute(
        toolListCellRendererFavorite.property_visible(), toolListColumns.isEditable);
    toolListCellRendererFavorite.signal_toggled().connect(
        sigc::mem_fun(*this, &ToolLocationPreference::Impl::favoriteToggled));
    initToolListRows(favorites);
    toolListViewPtr->expand_all();

    // Favorites list.
    favoritesViewPtr->append_column(favoritesViewColumnToolName);
    favoritesViewPtr->set_reorderable(true);
    favoritesViewColumnToolName.pack_start(favoritesCellRendererToolName);
    favoritesViewColumnToolName.set_renderer(
        favoritesCellRendererToolName, favoritesColumns.toolName);
    favoritesListEditButtons.getSignalRowsPreErase().connect(sigc::mem_fun(
        *this, &ToolLocationPreference::Impl::onFavoritesRowsPreRemove));
    favoritesViewPtr->get_selection()->set_mode(
        Gtk::SelectionMode::SELECTION_MULTIPLE);
    initFavoritesRows(favorites);
}

void ToolLocationPreference::Impl::favoriteToggled(const Glib::ustring &row_path)
{
    auto row_iter = toolListModelPtr->get_iter(row_path);
    const bool is_favorite = !row_iter->get_value(toolListColumns.isFavorite);
    const Tool tool = row_iter->get_value(toolListColumns.tool);

    // Update favorite column in the tool list.
    row_iter->set_value(toolListColumns.isFavorite, is_favorite);

    // Update the favorites list.
    if (is_favorite) {
        // Add to favorites list.
        auto new_favorite_row_iter = favoritesModelPtr->append();
        new_favorite_row_iter->set_value(
            favoritesColumns.toolName,
            M(getToolTitleKey(tool)));
        new_favorite_row_iter->set_value(favoritesColumns.tool, tool);
    } else {
        // Remove from favorites list.
        const auto favorites_rows = favoritesModelPtr->children();
        auto row = favorites_rows.begin();
        while (
            row != favorites_rows.end() &&
            row->get_value(favoritesColumns.tool) != tool) {
            row++;
        }
        if (row != favorites_rows.end()) {
            favoritesModelPtr->erase(row);
        }
    }
}

Tool ToolLocationPreference::Impl::getToolFromName(const std::string &name) const
{
    if (toolNamesReverseMap.empty()) {
        // Create the name to tool mapping.

        const auto panels = ToolPanelCoordinator::getDefaultToolLayout();
        std::vector<const ToolPanelCoordinator::ToolTree *> unprocessed_tool_trees;

        // Get the root tools from each panel.
        for (const auto &panel_tools : panels) {
            for (const auto &tool : panel_tools.second) {
                unprocessed_tool_trees.push_back(&tool);
            }
        }

        // Process all the tools, including their children.
        while (unprocessed_tool_trees.size() > 0) {
            const ToolPanelCoordinator::ToolTree *tool_tree =
                unprocessed_tool_trees.back();
            unprocessed_tool_trees.pop_back();
            toolNamesReverseMap[getToolName(tool_tree->id)] = tool_tree->id;
            for (const auto &child_tree : tool_tree->children) {
                unprocessed_tool_trees.push_back(&child_tree);
            }
        }
    }

    return toolNamesReverseMap.at(name);
}

void ToolLocationPreference::Impl::initFavoritesRows(
    const std::vector<Tool> &favorites)
{
    for (const auto tool : favorites) {
        auto favorite_row_iter = favoritesModelPtr->append();
        favorite_row_iter->set_value(
            favoritesColumns.toolName,
            M(getToolTitleKey(tool)));
        favorite_row_iter->set_value(favoritesColumns.tool, tool);
    }
}

void ToolLocationPreference::Impl::addToolListRowGroup(
    const std::vector<ToolPanelCoordinator::ToolTree> &tools,
    const Gtk::TreeIter &parentRowIter,
    const Favorites &favorites)
{
    for (const ToolPanelCoordinator::ToolTree &tool : tools) {
        auto tool_row_iter = toolListModelPtr->append(parentRowIter->children());
        tool_row_iter->set_value(
            toolListColumns.toolName,
            M(getToolTitleKey(tool.id)));
        tool_row_iter->set_value(toolListColumns.tool, tool.id);
        tool_row_iter->set_value(
            toolListColumns.isFavorite,
            favorites.count(tool.id) > 0);
        tool_row_iter->set_value(
            toolListColumns.isEditable,
            ToolPanelCoordinator::isFavoritable(tool.id));
        toolListToolToRowIterMap[tool.id] = tool_row_iter;
        addToolListRowGroup(tool.children, tool_row_iter, favorites);
    }
};

void ToolLocationPreference::Impl::initToolListRows(const std::vector<Tool> &favorites)
{
    const auto panel_tools = ToolPanelCoordinator::getDefaultToolLayout();
    Favorites favorites_set;

    for (const auto &tool : favorites) {
        favorites_set.insert(tool);
    }

    for (const auto panel : {
             ToolPanelCoordinator::Panel::EXPOSURE,
             ToolPanelCoordinator::Panel::DETAILS,
             ToolPanelCoordinator::Panel::COLOR,
             ToolPanelCoordinator::Panel::ADVANCED,
             ToolPanelCoordinator::Panel::LOCALLAB,
             ToolPanelCoordinator::Panel::TRANSFORM_PANEL,
             ToolPanelCoordinator::Panel::RAW,
         }) {
        auto tool_group_iter = toolListModelPtr->append();
        tool_group_iter->set_value(
            toolListColumns.toolName,
            M(getToolPanelTitleKey(panel)));
        addToolListRowGroup(panel_tools.at(panel), tool_group_iter, favorites_set);
    }
}

void ToolLocationPreference::Impl::onFavoritesRowsPreRemove(
    const std::vector<Gtk::TreeModel::Path> paths)
{
    // Unset the favorite column in the tools list for tools about to be removed
    // from the favorites list.
    for (const auto &path : paths) {
        const auto &row_iter = toolListToolToRowIterMap.at(
            favoritesModelPtr->get_iter(path)->get_value(favoritesColumns.tool));
        row_iter->set_value(toolListColumns.isFavorite, false);
    }
}

std::vector<Tool> ToolLocationPreference::Impl::toolNamesToTools(
    const std::vector<Glib::ustring> &tool_names) const
{
    std::vector<Tool> tool_set;

    for (auto &&tool_name : tool_names) {
        Tool tool;
        try {
            tool = getToolFromName(tool_name);
        } catch (const std::exception &e) {
            continue;
        }
        tool_set.push_back(tool);
    }

    return tool_set;
}

void ToolLocationPreference::Impl::updateOptions()
{
    const auto favorites_rows = favoritesModelPtr->children();
    options.favorites.resize(favorites_rows.size());
    for (unsigned i = 0; i < favorites_rows.size(); i++) {
        const Tool tool = favorites_rows[i].get_value(favoritesColumns.tool);
        options.favorites[i] = getToolName(tool);
    }
}

ToolLocationPreference::ToolLocationPreference(Options &options) :
    impl(new Impl(options))
{
    // Layout grid.
    Gtk::Grid *layout_grid = Gtk::manage(new Gtk::Grid());
    layout_grid->set_column_spacing(4);
    layout_grid->set_row_spacing(4);
    add(*layout_grid);

    // Tool list.
    Gtk::Frame *tool_list_frame = Gtk::manage(new Gtk::Frame(
        M("PREFERENCES_TOOLPANEL_AVAILABLETOOLS")));
    Gtk::ScrolledWindow *tool_list_scrolled_window =
        Gtk::manage(new Gtk::ScrolledWindow());
    tool_list_scrolled_window->set_min_content_width(550);
    layout_grid->attach_next_to(*tool_list_frame, Gtk::PositionType::POS_RIGHT, 1, 1);
    tool_list_frame->add(*tool_list_scrolled_window);
    tool_list_scrolled_window->add(*impl->toolListViewPtr);
    setExpandAlignProperties(
        tool_list_frame, false, true, Gtk::ALIGN_START, Gtk::ALIGN_FILL);

    // Favorites list.
    Gtk::Frame *favorites_frame = Gtk::manage(new Gtk::Frame(
        M("PREFERENCES_TOOLPANEL_FAVORITESPANEL")));
    Gtk::Box *favorites_box = Gtk::manage(new Gtk::Box());
    Gtk::ScrolledWindow *favorites_list_scrolled_window =
        Gtk::manage(new Gtk::ScrolledWindow());
    favorites_list_scrolled_window->set_min_content_width(400);
    layout_grid->attach_next_to(*favorites_frame, Gtk::PositionType::POS_RIGHT, 1, 1);
    favorites_box->pack_start(*favorites_list_scrolled_window, false, false);
    favorites_box->pack_start(impl->favoritesListEditButtons, false, false);
    favorites_frame->add(*favorites_box);
    favorites_list_scrolled_window->add(*impl->favoritesViewPtr);
    setExpandAlignProperties(
        favorites_frame, false, true, Gtk::ALIGN_START, Gtk::ALIGN_FILL);
}

void ToolLocationPreference::updateOptions()
{
    impl->updateOptions();
}