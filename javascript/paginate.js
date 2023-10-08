/**
====================================
Readme Sequelize Paginate Helper
====================================

## Usage
// require your model model
const { YOUR-MODEL } = require("<SEQUELIZE MODEL PATH>")

// require the paginate helper
const paginate = require("<PATH TO PAGINATE HELPER>")

// destruct the params
let { page, limit, search } = params

// import the paginate helper
const data = await paginate("<YOUR-MODEL>", page, limit, search)

// see the result
console.log(data.data, ">>>>>> result")

*/

module.exports = async (model, pageQuery, limitQuery, searchQuery) => {
  const page = parseInt(pageQuery) || 1;
  const limit = parseInt(limitQuery) || 10;
  const startIndex = (page - 1) * limit;
  const endIndex = page * limit;
  const results = {
    data: [],
    meta: {},
  };
  const total = await model.count();
  const totalPages = Math.ceil(total / limit);

  if (endIndex < total) {
    results.meta.next = page + 1;
  } else {
    results.meta.next = null;
  }

  if (startIndex > 0) {
    results.meta.previous = page - 1;
  } else {
    results.meta.previous = null;
  }

  results.meta.page = page;
  results.meta.total = total;
  results.meta.limit = limit;
  results.meta.totalPages = totalPages;

  try {
    results.data = await model.findAll({
      offset: startIndex,
      limit: limit,
      where: searchQuery,
    })
    
    return results;
  } catch (e) {
    return e;
  }
}